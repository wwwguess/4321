senn dodge book

inherit ITEM;

void create()
{

	set_name("踏雪无痕", ({"huashan miji", "book"}));
        set_weight(200);
        set("unit", "本");
        set("long", "这是华山派的身法秘籍「踏雪无痕」\n");
        set("value", 5000);
        set("material", "paper");
        set("skill", ([
                        "name": "dodge",      // name of the skill
                        "exp_required": 5000,  // minimum combat experience required
                        "sen_cost": 15+random(30),// gin cost every time study this skill
                        "difficulty":   20,     // the base int to learn this skill
			"max_skill" : 100
                      ]) );
}
