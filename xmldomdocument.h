#ifndef XMLDOMDOCUMENT_H
#define XMLDOMDOCUMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <string>

#include "architecture.h"

using namespace xercesc;
using namespace std;

class XmlDomDocument
{
    DOMDocument* m_doc;

private:
    XmlDomDocument();
    XmlDomDocument(const XmlDomDocument&);

public:
    XmlDomDocument(const char* xmlfile);
    ~XmlDomDocument();

    string getChildValue(const char* parentTag, int parentIndex,
                         const char* childTag, int childIndex);

    string getChildAttribute(const char* parentTag,
                             int parentIndex, const char* childTag,
                             int childIndex,
                             const char* attributeTag);

    int getChildCount(const char* parentTag, int parentIndex,
                      const char* childTag);

    int getRootElementCount(const char* rootElementTag);
    void outPutXMLFile(Architecture A);

    void DoOutput2Stream(DOMDocument *pmyDOMDocument);
};

#endif // XMLDOMDOCUMENT_H
