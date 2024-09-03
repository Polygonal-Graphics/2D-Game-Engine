namespace Polygame
{
  class GameObject;
  class ColliderComponent;

  // A class that takes in a scene root and performs collision checks on the colliders attached to GameObjects in that scene.
  class CollisionHandler
  {
    public:
    // Takes in a scene root and collects all collisions. Then, checks if dynamic colliders have collided with any
    // other dynamic colliders or static colliders, and calls their OnCollision methods.
    void CheckCollisions(GameObject* sceneRoot);

    private:
    // Checks if the given bounding boxes are colliding / overlapping.
    bool BoundingBoxCollisionCheck(ColliderComponent* colliderA, ColliderComponent* colliderB);
  }
}
