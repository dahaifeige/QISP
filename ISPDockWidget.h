#pragma once
#ifndef ISPDOCKWIDGET_H
#define ISPDOCKWIDGET_H
#include <QDockWidget>
#include <QApplication>
#include <memory>
class CameraItem;
namespace gcp2 {
	class Camera;
}
class ISPToolBox;
class ISPDockWidget :public QDockWidget
{
	
public:
	ISPDockWidget();
	~ISPDockWidget();

	static void SetCamera(std::shared_ptr<gcp2::Camera> pCamera) { m_pCamera = pCamera; }
	static std::shared_ptr<gcp2::Camera>  GetCamera() { return m_pCamera; }

	static void SetCameraItem(CameraItem* pCamItem) { m_pCamItem = pCamItem; }
	static CameraItem* GetCameraItem() { return m_pCamItem; }

private:
	ISPToolBox* m_toolBox;
	static std::shared_ptr<gcp2::Camera> m_pCamera;
	static CameraItem* m_pCamItem;
};

#endif
