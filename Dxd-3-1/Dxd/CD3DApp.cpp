#include "CD3DApp.h"

CD3DApp::CD3DApp(void)
{

}

CD3DApp::~CD3DApp(void)
{

}

HRESULT CD3DApp::InitD3D(HWND hWnd) 
{
	// Direct 3D ���� �ʱ�ȭ
	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	// Direct 3D �Ķ���� ����
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// back, front buffer�� ������ ��޶�
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;	// D3D format�� ������� �����ϰ� �ش޶�.

	// Direct 3D�� �̿��� Direct 3D Device�� ������ �޶�
	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&m_pd3dDevice)))
	{
		return E_FAIL;
	}

	OnInit();

	return S_OK;
}

void CD3DApp::Render() 
{
	if (NULL == m_pd3dDevice)
		return;

	// ����� �����
	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	// ������ �غ�
	m_pd3dDevice->BeginScene();

	// Render here
	OnRender();

	// ������ ����
	m_pd3dDevice->EndScene();

	// ���� ��ü(������ �ø���)
	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void CD3DApp::Update()
{
	OnUpdate();
}

void CD3DApp::Cleanup()
{
	OnRelease();

	if (m_pd3dDevice != NULL)
		m_pd3dDevice->Release();
	if (m_pD3D != NULL)
		m_pD3D->Release();
}

