#pragma once

namespace my
{
	//
	// このクラスはロック可能にします。
	//
	struct lockable_t
	{
		//
		// ロックカウントです。
		//
		int nb_locks = 0;

		//
		// ロックされている場合はTRUEを返します。
		//
		BOOL is_locked() const { return nb_locks != 0; }

		//
		// ロックします。
		//
		void lock() { nb_locks++; }

		//
		// ロックを解除します。
		//
		void unlock() { nb_locks--; }
	};

	//
	// このクラスはロック可能なオブジェクトをロックします。
	//
	struct locker_t {
		lockable_t* p;
		locker_t(lockable_t* p) : p(p) { p->lock(); }
		~locker_t() { p->unlock(); }
	};
}
