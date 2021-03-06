// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

int ask_qin(object me);
void create()
{
	set_name("戚四", ({ "kee si" , "kee"  }));
	set("title","落魄琴师");
	set("long",
	"一个穷困潦倒的琴师，满面风尘之色，背上斜背着一张琴。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("force", 30);
	set("max_force", 30);
	set("force_factor", 5);
	set("combat_exp", random(4000));
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"琴师不时的把背上的琴解下来抚弄一下，叹一口气，又把它给背上。\n",	
        }) );
	set("inquiry",([
		"琴"  : (: ask_qin :),
		"qin" : (: ask_qin :),
	]));
		
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/qin");
}

void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 3, me);
                return;
        }
}

void greeting(object me)
{
	if( me->query_temp("qin") )
		me->delete_temp("qin");
}

int ask_qin(object me)
{
	object ob;
	ob = this_object();

	message_vision("$N看着$n缓缓说道：这位"+RANK_D->query_respect(me)+
	"莫非也是懂琴之人。\n", ob, this_player());
	message_vision("$N从背上解下焦尾琴。\n", ob);	
	message_vision("$N长叹一声道：如果不是我...... 也罢，就让我来"+
	RANK_D->query_respect(me)+"弹上一曲。\n", ob);
	this_player()->set_temp("qin", 1);   
	ob->set_skill("unarmed", 120);
	ob->set_skill("dodge", 120);
	ob->set_temp("apply/attack", 100);
	ob->set_temp("apply/defense", 200);
	ob->set_temp("apply/damage", 80);
	ob->set("combat_exp", 200000);
	return 1;
}                                     

int accept_object(object who, object what)
{
	object obj;
	
	if( !who->query_temp("qin") ) {
		message_vision("$N淡淡的瞅了$n一眼，什么也没说。", this_object(), who);
		return 1;
	}
	if( !(obj = present("jiaowei qin", this_object()))) {
		message_vision("$N不好意思的对$n说：“你来晚一步，我的琴已经送人了。\n",
		this_object(), who);
		return 1;
	}
	if( what->query("money_id") && what->value() > 10000 ){
		tell_object(who,"琴师看着手中的琴，狠了狠心，说道：这位"+
		RANK_D->query_respect(who)+"乃是\n"
		"懂琴之人，想必不会暴疹天物。这琴于我已无意义，还是送与你吧！\n");
		obj->move(who);
		return 1;
	}
}
