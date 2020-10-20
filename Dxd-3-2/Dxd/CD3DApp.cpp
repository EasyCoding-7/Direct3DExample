#include "CD3DApp.h"

CD3DApp::CD3DApp(void)
{

}

CD3DApp::~CD3DApp(void)
{

}

HRESULT CD3DApp::InitD3D(HWND hWnd) 
{
	// Direct 3D 변수 초기화
	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	// Direct 3D 파라미터 선언
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// back, front buffer를 번갈아 써달라
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;	// D3D format을 윈도우와 동일하게 해달라.

	// Direct 3D를 이용해 Direct 3D Device를 생성해 달라
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

	// 백버퍼 지우기
	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	// 렌더링 준비
	m_pd3dDevice->BeginScene();

	// Render here
	OnRender();

	// 렌더링 종료
	m_pd3dDevice->EndScene();

	// 버퍼 교체(페이지 플리핑)
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

