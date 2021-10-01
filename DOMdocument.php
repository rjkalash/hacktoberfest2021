<?php
class DOMDocument extends DOMNode {
  /* Properties */
  public readonly string $actualEncoding;
  public readonly DOMConfiguration $config;
  public readonly DOMDocumentType $doctype;
  public readonly DOMElement $documentElement;
  public ?string $documentURI;
  public string $encoding;
  public bool $formatOutput;
  public readonly DOMImplementation $implementation;
  public bool $preserveWhiteSpace = true;
  public bool $recover;
  public bool $resolveExternals;
  public bool $standalone;
  public bool $strictErrorChecking = true;
  public bool $substituteEntities;
  public bool $validateOnParse = false;
  public string $version;
  public readonly ?string $xmlEncoding;
  public bool $xmlStandalone;
  public string $xmlVersion;
  /* Inherited properties */
  public readonly string $nodeName;
  public string $nodeValue;
  public readonly int $nodeType;
  public readonly ?DOMNode $parentNode;
  public readonly DOMNodeList $childNodes;
  public readonly ?DOMNode $firstChild;
  public readonly ?DOMNode $lastChild;
  public readonly ?DOMNode $previousSibling;
  public readonly ?DOMNode $nextSibling;
  public readonly ?DOMNamedNodeMap $attributes;
  public readonly ?DOMDocument $ownerDocument;
  public readonly ?string $namespaceURI;
  public string $prefix;
  public readonly string $localName;
  public readonly ?string $baseURI;
  public string $textContent;
  /* Methods */
  public __construct(string $version = "1.0", string $encoding = "")
  public createAttribute(string $localName): DOMAttr|false
  public createAttributeNS(?string $namespace, string $qualifiedName): DOMAttr|false
  public createCDATASection(string $data): DOMCdataSection|false
  public createComment(string $data): DOMComment|false
  public createDocumentFragment(): DOMDocumentFragment|false
  public createElement(string $localName, string $value = ""): DOMElement|false
  public createElementNS(?string $namespace, string $qualifiedName, string $value = ""): DOMElement|false
  public createEntityReference(string $name): DOMEntityReference|false
  public createProcessingInstruction(string $target, string $data = ""): DOMProcessingInstruction|false
  public createTextNode(string $data): DOMText|false
  public getElementById(string $elementId): ?DOMElement
  public getElementsByTagName(string $qualifiedName): DOMNodeList
  public getElementsByTagNameNS(?string $namespace, string $localName): DOMNodeList
  public importNode(DOMNode $node, bool $deep = false): DOMNode|false
  public load(string $filename, int $options = 0): DOMDocument|bool
  public loadHTML(string $source, int $options = 0): DOMDocument|bool
  public loadHTMLFile(string $filename, int $options = 0): DOMDocument|bool
  public loadXML(string $source, int $options = 0): DOMDocument|bool
  public normalizeDocument(): void
  public registerNodeClass(string $baseClass, ?string $extendedClass): bool
  public relaxNGValidate(string $filename): bool
  public relaxNGValidateSource(string $source): bool
  public save(string $filename, int $options = 0): int|false
  public saveHTML(?DOMNode $node = null): string|false
  public saveHTMLFile(string $filename): int|false
  public saveXML(?DOMNode $node = null, int $options = 0): string|false
  public schemaValidate(string $filename, int $flags = 0): bool
  public schemaValidateSource(string $source, int $flags = 0): bool
  public validate(): bool
  public xinclude(int $options = 0): int|false
  /* Inherited methods */
  public DOMNode::appendChild(DOMNode $node): DOMNode|false
  public DOMNode::C14N(
    bool $exclusive = false,
    bool $withComments = false,
    ?array $xpath = null,
    ?array $nsPrefixes = null
  ): string|false
  public DOMNode::C14NFile(
    string $uri,
    bool $exclusive = false,
    bool $withComments = false,
    ?array $xpath = null,
    ?array $nsPrefixes = null
  ): int|false
  public DOMNode::cloneNode(bool $deep = false): DOMNode|false
  public DOMNode::getLineNo(): int
  public DOMNode::getNodePath(): ?string
  public DOMNode::hasAttributes(): bool
  public DOMNode::hasChildNodes(): bool
  public DOMNode::insertBefore(DOMNode $node, ?DOMNode $child = null): DOMNode|false
  public DOMNode::isDefaultNamespace(string $namespace): bool
  public DOMNode::isSameNode(DOMNode $otherNode): bool
  public DOMNode::isSupported(string $feature, string $version): bool
  public DOMNode::lookupNamespaceUri(string $prefix): string
  public DOMNode::lookupPrefix(string $namespace): ?string
  public DOMNode::normalize(): void
  public DOMNode::removeChild(DOMNode $child): DOMNode|false
  public DOMNode::replaceChild(DOMNode $node, DOMNode $child): DOMNode|false
}
