#pragma once



namespace engine
{
	namespace gameplay
	{
		class Entity;

		class Components
		{
		protected:
			bool mIsActive{ true };
			Entity* mOwner;
			int mUpdateOrder;

		public:
			Components(Entity* pOwner);
			Components(Entity* pOwner, int pUpdateOrder); //Component constructor with owner and default update order

			inline bool Activate(bool pIsActive) { mIsActive = pIsActive ; }
			inline void SetOwner(Entity* pOwner) { mOwner = pOwner; }
			virtual void OnStart() = 0;
			virtual void Update() = 0;
			virtual void OnEnd() = 0;
		};
	}
}