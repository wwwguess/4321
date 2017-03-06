//NPC: /d/suzhou/npc/tianx.c
//by dwolf          
//97.11.6

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name(MAG"���Ķ�"NOR, ({"miao xiner", "miao" }));
        set("title", HIW"��Ƥ��"NOR);
        set("long",
                "����һ���ɰ���Ѿͷ����С�͸�����������\n"
        );

        set("gender", "Ů��");
        set("rank_info/respect", "��Ů");

        set("attitude", "peaceful");
        
        set("inquiry",([
                "������"  : (: ask_me :),
        ]));

        set("age", 30);
        set("shen_type", 10);
        set("str", 25);
        set("int", 30);
        set("con", 20);
        set("dex", 25);
	set("per", 25);
        set("max_kee", 200);
        set("max_gin", 40);
        set("force", 60);
        set("max_force", 60);
        set("force_factor", 10);
        set("combat_exp", 10000);
        set("score", 100000);
        set("apply/attack",  60);
        set("apply/defense", 36);

        set_skill("force", 30);
        set_skill("unarmed", 30);
        set_skill("sword", 30);
        set_skill("dodge", 40);
        set_skill("parry", 30);
      
        setup();
      
        add_money("silver", 10);
}

string ask_me()
{
	return "���Ķ�����Ц���������������Ǽ�С�㰡������";
}
