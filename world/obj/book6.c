// book.c

inherit ITEM;

void create()
{

	set_name( "乡书", ({ "book" }));
	set_weight(600);
	set("unit", "本");
	set("long", "这是时下读书人常看的书籍。\n");
	set("value", 900);
	set("skill", ([
		"name": 		"literate",		// name of the skill
		"exp_required":	0,				// minimum combat experience required
										// to learn this skill.
		"sen_cost":		40,				// gin cost every time study this
		"difficulty":	30,				// the base int to learn this skill
										// modify is gin_cost's (difficulty - int)*5%
		"max_skill":	50				// the maximum level you can learn
										// from this object.
	]) );
}
