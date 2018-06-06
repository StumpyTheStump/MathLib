#include "SceneObject.h"
#include "Renderer2D.h"
#include <assert.h>


SceneObject::SceneObject()
{
}

void SceneObject::addChild(SceneObject*child)
{
	assert(child->m_parent == nullptr);

	child->m_parent = this;

	m_children.push_back(child);
}

void SceneObject::removeChild(SceneObject*child)
{
	auto iter = std::find(m_children.begin(), m_children.end(), child);

	if (iter != m_children.end())
	{
		m_children.erase(iter);

		child->m_parent = nullptr;
	}
}

void SceneObject::onUpdate(float deltaTime)
{
}

void SceneObject::onDraw(aie::Renderer2D * renderer)
{
}

void SceneObject::update(float deltaTime)
{
	onUpdate(deltaTime);

	for (auto child : m_children)
		child->update(deltaTime);
}

void SceneObject::draw(aie::Renderer2D * renderer)
{
	onDraw(renderer);

	for (auto child : m_children)
		child->draw(renderer);
}




SceneObject::~SceneObject()
{
}
