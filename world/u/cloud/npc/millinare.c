// millinare , added by kindman

#include <ansi.h>

inherit NPC;	

void create()
{
        set_name("�Ű���", ({ "zhang" }) );
        set("title", "����");
        set("gender", "����" );
        set("age", 43);	
        set("long",
             "һλ�����ܸɵĴ����\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");

        set_skill("literate", 70);
        set_skill("dodge", 300);
        set_skill("unarmed", 200);
        setup();

        add_money("gold", 5);
}	
