
// qimenbagua
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;

void create()
{

        set_name("�ݼ�����", ({"qimen bagua", "book"}));
        set_weight(200);
        set("unit", "��");
        set("long", "�����һ�����ϰ���Ű��Ե���֮����\n");
        set("value", 5000);
        set("material", "paper");
        set("skill", ([
                        "name" : "qimen-bagua",     // name of the skill
                        "exp_required": 5000,  // minimum combat experience required
                        "sen_cost": 10+random(15),// gin cost every time study this skill
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":   69
                      ]) );
}
