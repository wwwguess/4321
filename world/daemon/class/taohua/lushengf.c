// lushengf.c     
//write by lysh
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("陆乘风", ({ "lu sheng feng", "feng", "lu" }) );
	set("gender", "男性" );
	set("age", 54);
	set("long", 
"他是黄药师的三弟子，是桃花岛四大弟子\n"
"陈、梅、曲、陆”中的功夫虽然不是最高，\n"
"但他是四大弟子中最为精通奇门八卦的一个。\n" 
"他看起来三十多岁，脸色枯黄，似乎身患重病，\n"
"身材甚高。肩窝下撑著一根拐杖。\n");
      
	set("title", RED "桃花岛" NOR + GRN +"弟子" NOR);
        set("gender", "男性");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 30);
        set("con", 24);
        set("dex", 28);
	set("per", 20);

        set("max_kee", 500);
        set("max_gin", 360);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);
	set("combat_exp", 100000);
        set("score", 2000);

        set("chat_chance_combat", 80);

	set_skill("literate", 70);
	set_skill("qimen-bagua", 70);
        set_skill("force", 70);
	set_skill("taohua-force", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("sword", 70);
        set_skill("yuxiao-jian", 70);
	
	set_skill("baguabu", 70);
        set_skill("hand", 70);
        set_skill("lanhua-shou", 70);
        set_skill("strike", 70);
        set_skill("luoying-zhang", 70);

	map_skill("force", "taohua-force");
        map_skill("parry", "lanhua-shou");
        map_skill("sword", "yuxiao-jian");
        map_skill("dodge", "baguabu");
        map_skill("strike", "luoying-zhang");
        map_skill("hand", "lanhua-shou");
	
        prepare_skill("strike", "luoying-zhang");
 	prepare_skill("hand", "lanhua-shou");

        create_family("桃花岛", 2, "弟子");

	set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);

      	setup();
        carry_object("/obj/weapon/gangjian")->wield();
        add_money("gold", 1);
}             

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

