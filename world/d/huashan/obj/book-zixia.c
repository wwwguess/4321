// book-zixia.c

inherit ITEM;

void create()
{

        set_name("��ϼ����", ({ "zixia miji", "miji" }));
        set_weight(200);
        set("unit", "��");
        set("long", "���ǻ�ɽ�ɵ��ڹ����š���ϼ���š�\n");
        set("value", 500);
        set("material", "paper");
        set("skill", ([
                        "name": "zixia-shengong",      // name of the skill
                        "exp_required": 10000,  // minimum combat experience required
                        "sen_cost": 15+random(30),// gin cost every time study this skill
                        "difficulty":   25,     // the base int to learn this skill
                        "max_skill":    99      // the maximum level you can learn
                      ]) );
}
