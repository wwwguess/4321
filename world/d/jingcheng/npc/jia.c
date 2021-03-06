// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("贾老实", ({ "jia laoshi" , "jia" , "laoshi" }));
	set("title",GRN"包子铺老板"NOR);
	set("nickname", HIY"包子王"NOR); 
	set("long",
	"贾老实也算是京城里的一个名人，他做的灌汤包子真是一绝，叫人吃了之后回味无穷。\n"
	"就连当今的皇上也赞不绝口，隔三岔五的也要差人来要一屉回去享受。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("kar", 20);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 2);
	set("combat_exp", 5000);
        set("vendor_goods", ([
           "蟹黄包子": __DIR__"obj/xhbaozi",
           "狗不理包子": __DIR__"obj/goubaozi",
           "羊肉包子": __DIR__"obj/yangbaozi",
           ])); 
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"贾老实热情的招呼你：这位客官，本店有上好的包子出售。\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
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
	command("pat "+me->query("id"));
	command("smile");
}
