//NPC:/d/suzhou/npc/lwliang.c  
//by dwolf
//97.11.4

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name(BLK"������"NOR, ({ "liang wanliang", "liang" }));
        set("title", YEL"�ӻ����ϰ�"NOR);
        set("shen_type", 10);

        set("gender", "����");
        set("age", 20);
        set("long",
                "��������һ������ԭ���Ե��ˣ������κܸ���Ȥ����֪��ô�������ӻ��̵��ƹ�\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/vest":5,
                __DIR__"obj/wanju":5,
		__DIR__"obj/whip":5,
        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
}
