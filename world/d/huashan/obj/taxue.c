senn dodge book

inherit ITEM;

void create()
{

	set_name("̤ѩ�޺�", ({"huashan miji", "book"}));
        set_weight(200);
        set("unit", "��");
        set("long", "���ǻ�ɽ�ɵ����ؼ���̤ѩ�޺ۡ�\n");
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
