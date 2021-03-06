#pragma once

#include "Hazel.h"

class Sandbox2D : public Hazel::Layer
{
public:
private:

	Hazel::OrthographicCameraController m_CameraController;

	// Temporary
	Hazel::Ref<Hazel::VertexArray> m_SquareVA;
	Hazel::Ref<Hazel::Shader> m_FlatColorShader;
	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	Hazel::Ref<Hazel::Texture2D> m_CheckerboardTexture;

	struct ProfileResult
	{
		const char* Name;
		float Time;
	};

	std::vector<ProfileResult> m_ProfileResults;

public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnEvent(Hazel::Event& event) override;
	void OnUpdate(Hazel::Timestep ts) override;

	virtual void OnImGuiRender() override;

private:

};