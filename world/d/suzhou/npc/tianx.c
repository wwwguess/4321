//NPC: /d/suzhou/npc/tianx.c
//by dwolf          
//97.11.6

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name(MAG"苗心儿"NOR, ({"miao xiner", "miao" }));
        set("title", HIW"调皮鬼"NOR);
        set("long",
                "她是一个可爱的丫头，从小就跟着苗若兰。\n"
        );

        set("gender", "女性");
        set("rank_info/respect", "美女");

        set("attitude", "peaceful");
        
        set("inquiry",([
                "苗若兰"  : (: ask_me :),
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
	return "苗心儿嘻嘻笑道，：“她是我们家小姐啊。！”";
}
