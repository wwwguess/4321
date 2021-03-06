//NPC:/d/suzhou/npc/gsnan.c 
//by dwolf   
//97.11.4
//changed by tlang
//97.12.4

#include <ansi.h>
inherit NPC;
mapping *step_phase;
mapping *read_table(string file);
int j;
string talk_me();

void create()
{
	set_name(YEL"左明珠"NOR, ({ "zuo mingzhu", "zuo"}) );
	set("gender", "女性" );
	set("age", 28);
        set("long",
		"她是一个可爱的女孩，不过她好象并不怎么温柔。\n");
	set("combat_exp", 50000);
	set("int",40);
	set("per",40);
	set("attitude", "heroism");
	set("rank_info/respect", "美女");
	set("pursuer", 1);                  
	set_skill("dodge",50);
	set_skill("blade",50);

	setup();
	add_money("gold",1);   
	carry_object("/d/hangzhou/npc/obj/sha.c")->wear(); 
	carry_object(__DIR__"obj/gangdao.c")->wield();
}

void init()
{ 
	add_action("give_talk", "talk");
}

int give_talk()
{
	object me;
	me=this_player();

	if( !me->query("mark/开始") ) 
		return notify_fail("你要干什么？\n");
 	command("say 准备好了吗？我们走吧。\n");
	step_phase = read_table("/u/t/tlang/step2");
        j=0; 
        remove_call_out("step");
	call_out("step", 5);
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
	int i;        
	
	if (this_object()->is_fighting())
        {command("say 有人要杀我，你还不快来帮忙？!\n");
	set("busy", 5);
        call_out("step", 1);
        return;
        }
        if (random(step_phase[j]["radom"])==1)             	
          {command("say 哎呀，这有坏人。\n");
	   set("busy", 5);
	   ob=new("/d/suzhou/npc/mmren.c");
	   ob->move(step_phase[j]["where"]);
	   ob->kill_ob(this_object());
	   for(i=0; i<2; i++) {
		if( objectp( obj = present("tangzi shou " + (i+1), environment(this_object())) ) )
				 obj->kill_ob(ob);	
		else	this_object()->kill_ob(ob);		
	   }
           call_out("step", 1);
         return;
	  }
	command(step_phase[j]["command"]);
        j++;
        if (j==sizeof(step_phase))
	{command("say 镖银我已给你们副总镖头了。谢谢你了。\n");
	 this_player()->delete("mark/开始");
	 this_player()->delete("mark/护镖");
	 this_player()->set("mark/成功", 1);
	 destruct(this_object());
	       	 return;
         }
	call_out("step", 1);
}

