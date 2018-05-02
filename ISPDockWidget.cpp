#include "ISPDockWidget.h"
#include "ISPToolBox.h"
#include "Camera.h"
#include "CameraItem.h"
std::shared_ptr<gcp2::Camera> ISPDockWidget::m_pCamera = 0;
CameraItem* ISPDockWidget::m_pCamItem = nullptr;
ISPDockWidget::ISPDockWidget():
m_toolBox(new ISPToolBox)
{
	setWidget(m_toolBox);
	setWindowTitle(QApplication::translate("MainWindow", "ISP", Q_NULLPTR));

}

ISPDockWidget::~ISPDockWidget()
{
}

