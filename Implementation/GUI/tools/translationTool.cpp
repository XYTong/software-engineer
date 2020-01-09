#include "translationTool.h"

bool TranslationTool::initTool(toolParameters_t *param){
    mat = param->mat;
    colorVect = param->colorVect;
    delete param;
    return true;
}

bool TranslationTool::useTool(){
    QImage *qPic = new QImage(pic->getCurrentLayerAsQ()->transformed(mat));
    qPic->setColorTable(colorVect);
    QImage *qPic2 = new QImage(qPic->convertToFormat(QImage::Format_Indexed8));
    pic->addCurrentLayer(qPic2);
    return true;
}
