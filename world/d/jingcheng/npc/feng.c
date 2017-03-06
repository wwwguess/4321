// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("丰有福", ({ "feng youfu", "feng" , "youfu" }));
	set("title",GRN"粮店老板"NOR);
	set("long",
	"丰记粮店的老板，他有财有势，而且为人和善，经常放义粮，深得四方民众的爱戴。\n");
	set("gender", "男性");
	set("age", 33);
       set("vendor_goods",([
         __DIR__"obj/dami.c":20,
         ]));
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("combat_exp", 10000);
	set_skill("dodge", 20);
	set_skill("unarmed", 50);
	set_temp("apply/defense", 10);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"丰有福捋着颌下三缕长须说道：如今天下太平，真是百姓有福啊。\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
        add_action("do_vendor_list","list");
        add_action("do_work","work");
        if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	command("say "+RANK_D->query_respect(me)+"想到这儿打工挣钱吗？\n");
}
int do_work()
{
int kee;
object me,ob;
me = this_player();
kee=me->query("kee");
if (kee<30) return notify_fail("丰有福说：“想把自己累死么！”\n");
kee=kee-30;
me->set("kee",kee);
ob=new("/obj/money/silver");
ob->move(me);
message_vision("$N劳累的干起活来。\n",me);
return notify_fail("丰有福说：“干的不错，这是工钱。”\n");
}
