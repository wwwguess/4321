// book-parry.c

inherit ITEM;

void create()
{

        set_name("̤ѩ�޺�", ({ "taxuewuheng", "taxue" }));
        set_weight(200);
        set("unit", "��");
        set("long", "���ǻ�ɽ�ɵ����ؼ���̤ѩ�޺ۡ�\n");
        set("value", 5000);
        set("material", "paper");
        set("skill", ([
                        "name": "parry",      // name of the skill
                        "exp_required": 5000,  // minimum combat experience required
                        "jing_cost": 15+random(30),// gin cost every time study this skill
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":   70     // the maximum level you can learn
                      ]) );
}
