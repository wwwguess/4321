// Created by kiss
// Data: 1997.10.27         

               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
	set_name("刘二娘", ({ "liu er niang" , "liu" , "niang" }));
	set("title", CYN"绢帛店老板娘"NOR); 
	set("long",@LONG 
他就是刘家绢帛店的老板娘
一双巧手，做出来的衣服可是
供不应求，
LONG 
    );
	set("gender", "女性");
	set("age", 25);
	set("attitude", "peaceful");
	set("vendor_goods", ([
		"二龙抢珠金抹额":__DIR__"obj/moe.c" ,
		"石青起花八团倭缎排穗褂":__DIR__"obj/gua.c" ,
                "五彩丝攒花结长穗宫绦":__DIR__"obj/tao.c" ,
                "束发嵌宝紫金冠":__DIR__"obj/hat1.c",
                "百蝶穿花大红箭袖":__DIR__"obj/jianxiu.c",
	]));

	set("str", 30);
	set("int", 20);
	set("con", 15);
	set("kar", 20);
	set("per", 30);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 2);
	set("combat_exp", 20000);
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"刘二娘志得意满的说：“我们小店的衣服可是京城出了名的哦！”\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
	seteuid(geteuid());
	add_action("do_vendor_list","list");
	
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}

void greeting(object me)
{	
	if( !me || environment(me) != environment() ) return;
 	command("say 这位"+(string)RANK_D->query_respect(me)+"可是要选购衣物？\n");
	command("smile");
	command("say 本店经营有方，包你满意。\n");
}
