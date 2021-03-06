//NPC:/d/suzhou/npc/longwu.c
//by dwolf
//9711.4
//changed by tlang
//97.12.3
       
#include <ansi.h>
inherit NPC;
mapping *step_phase;
mapping *read_table(string file);
int j;
string talk_me();
string ask_for_hubiao();

void create()
{
        set_name(YEL"龙五"NOR, ({"long wu", "longwu", "long" }));
	set("title", HIW"总镖头"NOR);
	set("long", @LONG
他是镖局的总镖头龙五，由于年纪太大，现在已经不管事了。据说他是少林俗家弟子中
的高手。
LONG
	);

	set("gender", "男性");
	set("attitude", "heroism");
	
	set("age", 25);
	set("shen_type", 100);
	set("str", 25);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	set("per", 25);
	set("max_kee", 800);
	set("max_gin", 300);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("combat_exp", 300000);
	set("score", 100000);
	set("apply/attack",  50);
	set("apply/defense", 50);

	set_skill("force", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("cibei-dao", 100);
	set_skill("hunyuan-yiqi", 100);
        set_skill("strike", 100);
	set_skill("sanhua-zhang", 100);

        map_skill("strike", "sanhua-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("strike", "sanhua-zhang"); 
	set("count", 1);   
	
	set("inquiry", ([
		"护镖" : (: ask_for_hubiao :),
	]));

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("gold", 2);
}  

void init()
{ 
	add_action("give_talk", "talk");
	add_action("do_join", "join");
        add_action("do_want", "want");
}

int do_join(string arg)
{
	object me;
	me=this_player();

	if( me->query("combat_exp") <= 100000) 
		return notify_fail("你的的经验太低，不适于加入镖局。\n");
	else {
	if ( me->query("mark/镖局") )
		return notify_fail("你已经加入了。\n");
/*
	if( !arg || arg !="镖局") return 0;*/
	me->set("mark/镖局", 1);
	command("say 我就把你收下吧。\n");
		return 1;
	}
	return 1;
}

int give_talk()
{       
	mapping fam;
        object me;
	me = this_player();
	if ((int)me->query_skill("blade") >= 100)
        
	return command("say 小兄弟已经不错，今后就要靠自己找师傅学了，呵呵."); 
	
	if (query("count") < 1)
		return command("hehe");
	
	add("count", -1);    
	
	me->improve_skill("blade", 50);
	write("你和龙总镖头的谈话让你的基本刀法有了进步。\n");
	return 1;
}

string ask_for_hubiao()
{
	object me;
	me = this_player();
	
	if( me->query("mark/镖局") )
	{
		if( me->query("mark/护镖") )
        		return RED"你还没有把镖送到，怎么又来了?\n"NOR;        
       		if(query("count") < 1)
                	return "抱歉，你来晚了，这次的镖已经有人护送了，等下次吧。\n";

                add("count", -1);

                me->set_temp("pending/hubiao", 1);
                        return "你想护镖，这是好事，但路上危险，你可愿意(want)？\n";
        }  else {
                return "你没有加入我们镖局，不能护镖。\n";
        }
}

int do_want()
{
	object me;
	me=this_player();

	if( !me->query_temp("pending/hubiao") ) 
		return notify_fail("你要干什么？\n");
 	me->set("mark/护镖");
	command("say 你要护镖，这是好事，跟我(follow)来。我带你去找副总镖头要任务。\n");
	step_phase = read_table("/u/t/tlang/step1");
        j=0; 
        remove_call_out("step");
	call_out("step",5);
		return 1;
}
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]==	'#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]]);
		fn = (++fn) % sizeof(field);        
		if( !fn ) ++rn;
	}
	return data;
}


void step()
{        
	object ob,obj;
	if (this_object()->is_fighting())
        {command("say 有人要杀我，你还不快来帮忙？!\n");
        call_out("step",1);
        return;
        }
        if (random(step_phase[j]["radom"])==1)             	
          {command("say 哎呀，这有杀手。\n");
	   ob=new("/d/suzhou/npc/mmren.c");
	   ob->move(step_phase[j]["where"]);
	   ob->kill_ob(this_object());
           call_out("step", 1);
         return;
	  }
	command(step_phase[j]["command"]);
        j++;
        if (j==sizeof(step_phase))
	{obj=new("/d/suzhou/npc/obj/flag.c");
         obj->move(this_player());
	 command("say 这面镖旗给你拿着，其他事让江镖头给你说。我走了。\n");
	 this_player()->set("mark/护镖", 1);
	 this_object()->move("/d/suzhou/hfang");
         	 return;
         }
	call_out("step", 1);
}


	

