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
			Components(Entity* pOwner, int pUpdateOrder, bool pActive = true); //Component constructor with owner and default update order

			inline bool Activate(bool pIsActive) { mIsActive = pIsActive ; }
			inline Entity* GetOwner() { return mOwner; }
			virtual void OnStart() = 0;
			virtual void Update() = 0;
			virtual void OnEnd() = 0;
		};
	}
}