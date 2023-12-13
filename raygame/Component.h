#pragma once
class Actor;

class Component
{
public:
	Component();
	Component(Actor* owner, const char* name);

	virtual ~Component();

	/// <summary>
	/// Called before the first update.
	/// </summary>
	virtual void start() {};

	/// <summary>
	/// Called everytime the game loops
	/// </summary>
	/// <param name="deltaTime">The amount of time that has passed 
	/// between this frame and the previous frame.</param>
	virtual void update(float deltaTime) {};

	/// <summary>
	/// Called after update in order to update the visuals.
	/// </summary>
	virtual void draw() {};

	/// <summary>
	/// Called when the scene ends 
	/// or when an actor is removed.
	/// </summary>
	virtual void end() {};

	/// <summary>
	/// Called when this actors collider makes contact with another actors collider
	/// </summary>
	/// <param name="other">The actor this actor collided with.</param>
	virtual void onCollision(Actor* other) {};

	/// <summary>
	/// Called when this actor is about to be destroyed
	/// </summary>
	virtual void onDestroy() {};

	/// <returns>Gets the name of this component.
	/// Is usually the type name.</returns>
	const char* getName() { return m_name; }

	/// <returns>Gets the actor this component is attached to.</returns>
	Actor* getOwner() { return m_owner; }

private:
	const char* m_name;
	Actor* m_owner;
};

