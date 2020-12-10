#include "text.h"
#include <cad/primitive/text.h>

using namespace lc::builder;

TextBuilder::TextBuilder()
    :
    _underlined(false),
    _strikethrough(false),
    _bold(false),
    _italic(false)
{
}

TextBuilder* TextBuilder::setUnderlined(bool underline) {
    _underlined = underline;
    return this;
}

bool TextBuilder::underlined() const {
    return _underlined;
}

TextBuilder* TextBuilder::setStrikethrough(bool strikethrough) {
    _strikethrough = strikethrough;
    return this;
}

bool TextBuilder::strikethrough() const {
    return _strikethrough;
}

TextBuilder* TextBuilder::setBold(bool bold) {
    _bold = bold;
    return this;
}

bool TextBuilder::bold() const {
    return _bold;
}

TextBuilder* TextBuilder::setItalic(bool italic) {
    _italic = italic;
    return this;
}

bool TextBuilder::italic() const {
    return _italic;
}

lc::entity::Text_CSPtr TextBuilder::build() {
    checkValues(true);
    return entity::Text_CSPtr(new entity::Text(*this));
}

void TextBuilder::copy(lc::entity::Text_CSPtr entity) {
    CADEntityBuilder::copy(entity);

    setInsertionPoint(entity->insertion_point());
    setTextValue(entity->text_value());
    setTextFont(entity->style());
    setHeight(entity->height());
    setAngle(entity->angle());
    setDrawingDirection(entity->textgeneration());
    setHorizontalAlign(entity->halign());
    setVerticalAlign(entity->valign());
    setUnderlined(entity->underlined());
    setStrikethrough(entity->strikethrough());
    setBold(entity->bold());
    setItalic(entity->italic());
}
