#pragma once
#include <vector>
class SceneObject
{
public:
	SceneObject();
	virtual ~SceneObject()
	{
		if (m_parent != nullptr)
			m_parent->removeChild(this);

		for (auto child : m_children)
			child->m_parent = nullptr;
	}

	SceneObject* getParent() const { return m_parent; }
	size_t childCount() const { return m_children.size(); }
	SceneObject* getChild(unsigned int index) const
	{
		return m_children[index];
	}

	void addChild(SceneObject * child);
	void removeChild(SceneObject * child);

	virtual void onUpdate(float deltaTime);
	virtual void onDraw(aie::Renderer2D * renderer);

	void update(float deltaTime);

	void draw(aie::Renderer2D * renderer);

protected:

	SceneObject * m_parent = nullptr;
	std::vector<SceneObject*> m_children;
};

