#include <numeric>
namespace hellmath {


// using namespace std;
// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
	enum class AccountStatus {
		mod,
		troll,
		guest,
		user,
	};

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
	enum class Action {
		read,
		write,
		remove,
	};

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
	bool display_post(AccountStatus poster, AccountStatus viewer) {

		if (viewer == AccountStatus::troll && poster == AccountStatus::troll) {
			return true;
		}

		switch(poster) {
		case AccountStatus::user:
			return true;
		case AccountStatus::mod:
			return true;
		case AccountStatus::guest:
			return true;
		default:
			return 0;
		}
	}

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
	bool permission_check(Action action, AccountStatus status) {

		bool out = false;

		switch(status) {
		case AccountStatus::mod:

			switch(action) {
			case Action::read:
				out = true;
				return out;
			case Action::remove:
				out = true;
				return out;
			case Action::write:
				out = true;
				return out;
			default:
				return out;
			}
		case AccountStatus::user:

			switch(action) {
			case Action::read:
				out = true;
				return out;
			case Action::remove:
				out = false;
				return out;
			case Action::write:
				out = true;
				return out;
			default:
				return out;
			}
		case AccountStatus::guest:

			switch(action) {
			case Action::read:
				out = true;
				return out;
			case Action::remove:
				out = false;
				return out;
			case Action::write:
				out = false;
				return out;
			default:
				return out;
			}
		case AccountStatus::troll:

			switch(action) {
			case Action::read:
				out = true;
				return out;
			case Action::remove:
				out = false;
				return out;
			case Action::write:
				out = true;
				return out;
			default:
				return out;
			}
		default:
			return out;
		}

	}

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
	bool valid_player_combination(AccountStatus player1, AccountStatus player2) {


		if (player1 == AccountStatus::guest || player2 == AccountStatus::guest) {
			return false;
		}
		if (player1 == AccountStatus::user || player2 == AccountStatus::user) {
			if (player2 == AccountStatus::user && player1 == AccountStatus::user) {
				return true;
			}
			if ((player2 == AccountStatus::user && player1 == AccountStatus::mod) || (player1 == AccountStatus::user && player2 == AccountStatus::mod)) {
				return true;
			}
		}
		if (player1 == AccountStatus::mod && player2 == AccountStatus::mod) {
			return true;
		}
		if(player1 == AccountStatus::troll && player2 == AccountStatus::troll) {
			return true;
		} else {
			return false;
		}
		return 0;
	}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
	bool has_priority(AccountStatus player1, AccountStatus player2) {

		bool out = false;

		// Mod has highest priority
		if(player1 == AccountStatus::mod) {

			switch(player2) {
			case AccountStatus::guest:
				out = true;
				return out;
			case AccountStatus::user:
				out = true;
				return out;
			case AccountStatus::troll:
				out = true;
				return out;
			case AccountStatus::mod:
				out = false;
				return out;
			default:
				return false;
			}
		}
		// user have second highest
		if(player1 == AccountStatus::user) {

			switch(player2) {
			case AccountStatus::guest:
				out = true;
				return out;
			case AccountStatus::user:
				out = false;
				return out;
			case AccountStatus::mod:
				out = !true;
				return out;
			case AccountStatus::troll:
				out = true;
				return out;
			default:
				return false;
			}
		}
		// guests hve second lowest priority
		if(player1 == AccountStatus::guest) {

			switch(player2) {
			case AccountStatus::guest:
				out = false;
				return out;
			case AccountStatus::troll:
				out = true;
				return out;
			case AccountStatus::user:
				out = !true;
				return out;
			case AccountStatus::mod:
				out = false;
				return out;
			default:
				return false;
			}
		}
		// trolls have lowest priority
		if(player1 == AccountStatus::troll) {

			switch (player2) {
				case AccountStatus::guest:
				out = false;
				return out;
			case AccountStatus::troll:
				out = false;
				return out;
			case AccountStatus::user:
				out = false;
				return out;
			case AccountStatus::mod:
				out = false;
				return out;
			default:
				return false;
			}
		}
		return out;
	}



}  // namespace hellmath