inherit SKILL;

mapping *quest = ({
	([	"quest":	"œÆ»À",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"…’∑π…Æ",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"—¸¥¯",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"«‡…¥»π",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"[33møÕ»À[2;37;0m",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"[33mƒ–÷˜»À[2;37;0m",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"[33m≈Æ÷˜»À[2;37;0m",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"[33m–„≤≈[2;37;0m",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"–°‘∞π§",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"≤√∑Ï",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"¡ø“¬≥ﬂ",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"≤√“¬ºÙ",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"‘∞π§ºÙ",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"∑ºÁ±",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"√‡»π",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"[35m–«Àﬁ≈…[2;37;0m[33mÓ‡ ÷[2;37;0m",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"Õ≠Ó‡",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"º÷¿œ µ",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"…Ò∏∏",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"À·–„≤≈",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"¬√øÕ",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"∂≈øÌ",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"¥ÛÛØÚÎ",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"¡˜√•",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"ΩœÓ¡¥",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"[1;37m”≠∑Ô[2;37;0m",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"∑…‘Ù",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"[35m–«Àﬁ≈…[2;37;0m[33m∫≈ ÷[2;37;0m",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"Õ≠∫≈",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"“π––“¬",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"ª∆Ω",
		"quest_type":	"—∞",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"‘∞π§",
		"quest_type":	"…±",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
