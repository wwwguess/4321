// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("萧萧", ({ "xiao xiao", "xiao" }));
	set("title",GRN"兵器铺女老板"NOR);
	set("nickname", RED"多情娘子"NOR);
	set("long",
	"她是老英雄萧振远的小女儿，兵器铺女老板．由于善使独门兵刃－－柔情剑，\n"
	"巾帼不让须眉，江湖上人称「多情娘子」。\n");
	set("gender", "女性");
	set("age", 22);
	set("attitude", "heroism");
        set("vendor_goods", ([
           "短剑":__DIR__"obj/duanjian",
           "长剑":__DIR__"obj/changjian",
           "钢剑":__DIR__"obj/gangjian",
           "钢刀":__DIR__"obj/gangdao",
           "铁棍":"/d/xingxiu/obj/tiegun",
           "羊鞭":"/d/xingxiu/obj/bian",
           "铁锤":"/obj/weapon/hammer",
        ]));
   
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("per", 40);
	set("combat_exp", 60000+random(15000));
	set_skill("dodge", 100);
	set_skill("unarmed", 80);
	set_skill("sword", 120);
	set_skill("force",120);
	set_temp("apply/defense", 40);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"萧萧风情万重的看了你一眼，说道：“这位客官好俊啊。”\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/gangjian")->wield();
}
void init()
{
	object me;
    	::init();
        add_action("do_vendor_list", "list");
 
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}

void greeting(object me)
{
	object obj;
	command("lovelook");
}
