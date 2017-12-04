#include <stdio.h>
#include "xmldomdocument.h"

class XmlDomErrorHandler : public HandlerBase
{
  public:
    void fatalError(const SAXParseException &exc) {
        printf("Fatal parsing error at line %d\n", (int)exc.getLineNumber());
        exit(-1);
    }
};

XercesDOMParser*   parser = NULL;
ErrorHandler*      errorHandler = NULL;


void createParser()
{
    if (!parser)
    {
        XMLPlatformUtils::Initialize();
        parser = new XercesDOMParser();
        errorHandler = (ErrorHandler*) new XmlDomErrorHandler();
        parser->setErrorHandler(errorHandler);
    }
}

template <typename T>
string NtoS(T pNumber)
{
 ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}

XmlDomDocument::XmlDomDocument()
{

}

XmlDomDocument::XmlDomDocument(const char* xmlfile) : m_doc(NULL)
{
    createParser();
    parser->parse(xmlfile);
    m_doc = parser->adoptDocument();
}

string XmlDomDocument::getChildValue(const char* parentTag, int parentIndex, const char* childTag, int childIndex)
{
    XMLCh* temp = XMLString::transcode(parentTag);
    DOMNodeList* list = m_doc->getElementsByTagName(temp);
    XMLString::release(&temp);

    DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
    DOMElement* child =
        dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));
    string value;
    if (child) {
        char* temp2 = XMLString::transcode(child->getTextContent());
        value = temp2;
        XMLString::release(&temp2);
    }
    else {
        value = "";
    }
    return value;
}

string XmlDomDocument::getChildAttribute(const char* parentTag, int parentIndex, const char* childTag, int childIndex,
                                         const char* attributeTag)
{
    XMLCh* temp = XMLString::transcode(parentTag);
    DOMNodeList* list = m_doc->getElementsByTagName(temp);
    XMLString::release(&temp);

    DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
    DOMElement* child =
        dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));
    string value;
    if (child) {
        temp = XMLString::transcode(attributeTag);
        char* temp2 = XMLString::transcode(child->getAttribute(temp));
        value = temp2;
        XMLString::release(&temp2);
    }
    else {
        value = "";
    }

    return value;
}

int XmlDomDocument::getRootElementCount(const char* rootElementTag)
{
    DOMNodeList* list = m_doc->getElementsByTagName(XMLString::transcode(rootElementTag));
    return (int)list->getLength();
}

void XmlDomDocument::outPutXMLFile(Architecture A)
{
    // Initilize Xerces.
    XMLPlatformUtils::Initialize();

    // Pointeur sur la DOMImplementation.
    DOMImplementation* p_DOMImplementation = NULL;
    p_DOMImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

    // Pointeur sur le DOMDocument.
    DOMDocument* p_DOMDocument = NULL;

    XMLCh* docName = XMLString::transcode("architecture");
    p_DOMDocument = p_DOMImplementation->createDocument(0, docName, 0);

    DOMElement * p_RootElement = NULL;
    p_RootElement = p_DOMDocument->getDocumentElement();

    //Remplissage du document
    //Creation d'un noeud commentaire, puis l'ajout au document.
    DOMComment * p_DOMComment = NULL;
    p_DOMComment = p_DOMDocument->createComment(XMLString::transcode("Parameter file for architecture"));
    p_DOMDocument->appendChild(p_DOMComment);

    //Creation d'un noeud, ajout d'attributs, puis ajout au noeud racine.
    DOMElement * p_ArchiElement = NULL;
    p_ArchiElement = p_DOMDocument->createElement(XMLString::transcode("buses"));

    p_RootElement->appendChild(p_ArchiElement);

    //Convert an integer to a string, then set/create the attribute.
    int nbbuses = A.getBuses().size();
    p_ArchiElement->setAttribute(XMLString::transcode("nbbuses"), XMLString::transcode(NtoS(nbbuses).c_str()));

    // Creation d'un noeud, ajout d'attributs,
    // puis ajout à p_ArchiElement.
    DOMElement * p_Bus = NULL;

    for(int i = 0; i < nbbuses; ++i){
        p_Bus = p_DOMDocument->createElement(XMLString::transcode("bus"));

        p_Bus->setAttribute(XMLString::transcode("name"), XMLString::transcode(A.getBuses().at(i).getName().c_str()));
        p_Bus->setAttribute(XMLString::transcode("nbports"), XMLString::transcode(NtoS(A.getBuses().at(i).getNb_ports()).c_str()));
        p_Bus->setAttribute(XMLString::transcode("bandwidth"), XMLString::transcode(NtoS(A.getBuses().at(i).getBandwith()).c_str()));
        p_Bus->setAttribute(XMLString::transcode("type"), XMLString::transcode(A.getBuses().at(i).getType().c_str()));

        p_ArchiElement->appendChild(p_Bus);
    }

    //Output
    DoOutput2Stream(p_DOMDocument);

    // Cleanup.
    p_DOMDocument->release();
    XMLPlatformUtils::Terminate();

}

int XmlDomDocument::getChildCount(const char* parentTag, int parentIndex, const char* childTag)
{
    XMLCh* temp = XMLString::transcode(parentTag);
    DOMNodeList* list = m_doc->getElementsByTagName(temp);
    XMLString::release(&temp);

    DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
    DOMNodeList* childList = parent->getElementsByTagName(XMLString::transcode(childTag));
    return (int)childList->getLength();
}

void XmlDomDocument::DoOutput2Stream(DOMDocument* pmyDOMDocument)
{
    DOMImplementation    *pImplement    = NULL;
    DOMLSSerializer      *pSerializer   = NULL;
    XMLFormatTarget      *pTarget       = NULL;

    /*
    Return the first registered implementation that has
    the desired features. In this case, we are after
    a DOM implementation that has the LS feature... or Load/Save.
    */
    pImplement = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("LS"));

    /*
    From the DOMImplementation, create a DOMWriter.
    DOMWriters are used to serialize a DOM tree [back] into an XML document.
    */
    pSerializer = ((DOMImplementationLS*)pImplement)->createLSSerializer();

    /*
    This line is optional. It just sets a feature
    of the Serializer to make the output
    more human-readable by inserting line-feeds and tabs,
    without actually inserting any new nodes
    into the DOM tree. (There are many different features to set.)
    Comment it out and see the difference.
    */

    //The end-of-line sequence of characters to be used in the XML being written out.
    pSerializer->setNewLine(XMLString::transcode("\n"));

    DOMConfiguration* pDomConfiguration = pSerializer->getDomConfig();
    pDomConfiguration->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);


    /*
    Choose a location for the serialized output. The 3 options are:
    1) StdOutFormatTarget     (std output stream -  good for debugging)
    2) MemBufFormatTarget     (to Memory)
    3) LocalFileFormatTarget  (save to file)
    (Note: You'll need a different header file for each one)
    */
    /** 1) **/
    /*pTarget = new StdOutFormatTarget();
    DOMLSOutput* pDomLsOutput = ((DOMImplementationLS*)pImplement)->createLSOutput();
    pDomLsOutput->setByteStream(pTarget);

    // Write the serialized output to the target.
    pSerializer->write(pmyDOMDocument, pDomLsOutput);*/

    /** OR **/
    /** 3) **/
    pTarget = new LocalFileFormatTarget("./XML_files/arch_jbod2.xml");
    // Write the serialized output to the target.
    DOMLSOutput* pDomLsOutput = ((DOMImplementationLS*)pImplement)->createLSOutput();
    pDomLsOutput->setByteStream(pTarget);

    pSerializer->write(pmyDOMDocument, pDomLsOutput);

    pSerializer->release();
    delete pTarget;
    pDomLsOutput->release();
}

XmlDomDocument::~XmlDomDocument()
{
    if (m_doc) m_doc->release();
}
