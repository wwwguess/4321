inherit SKILL;

mapping *quest = ({
	([	"quest":	"¸ğÂ×",
		"quest_type":	"É±",
		"exp_bonus":	150,
		"shen_type":	0,
	]),

	([	"quest":	"¾Å»·ìøÕÈ",
		"quest_type":	"Ñ°",
		"exp_bonus":	150,
		"shen_type":	0,
	]),

	([	"quest":	"Ñî¹ı",
		"quest_type":	"É±",
		"exp_bonus":	150,
		"shen_type":	1,
	]),

	([	"quest":	"[1;32mĞşÌú½£[2;37;0m",
		"quest_type":	"Ñ°",
		"exp_bonus":	150,
		"shen_type":	1,
	]),

	([	"quest":	"»ÒÉ«µÀÅÛ",
		"quest_type":	"Ñ°",
		"exp_bonus":	150,
		"shen_type":	1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
