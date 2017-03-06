inherit NPC;
#include <ansi.h>
mapping *step_phase;
mapping *read_table(string file);
int j;
void create()
{
	set_name("寂微", ({ "ji wei", "ji", "wei" }) );

	set("gender", "女性");
	set("age", 14);
	set("per",30);
	set("attitude", "peaceful");
	set("weight",90000);
	set("chat_chance",10);
	set("chat_msg",({"寂微说:谁愿意把我送回家?\n",
                         "寂微说:路上的小流氓我怕怕。\n",
			 "寂微说:愿意送我回家的用quest命令。\n",
              }));
	set("jingli",400);
      	set("str", 10);
	set("cor", 30);
	set("int", 24);
	set("dex", 30);
        set("title", "无知女童");
	set("combat_exp",300);
        set("kee",300);
	setup();

}
void init()
{
        add_action("give_quest", "quest");
}
int give_quest()
{
 	command("say 谢谢你送我回家。follow me ok?");
	step_phase = read_table("/u/lysh/step");
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
	object ob;
	if (this_object()->is_fighting())
        {command("say 救命呀，小流氓要杀我!");
        call_out("step",8);
        return;
        }
        if (random(step_phase[j]["radom"])==1)             	
          {command("say 哎呀，这有个小流氓。");
	   ob=new("/d/village/npc/punk.c");
	   ob->move(step_phase[j]["where"]);
	   ob->kill_ob(this_object());
           call_out("step", 6);
         return;
	  }
	command(step_phase[j]["command"]);
        j++;
        if (j==sizeof(step_phase))
	{ob=new("/u/lysh/jinyb.c");
         ob->move("/d/mingrentang/wlysh");
	 command("say 谢谢你送我回家，家里的金元宝给你留做纪念。");
         this_object()->move("/u/lysh/workroom");
	 	 return;
         }
	call_out("step", 2);
}
