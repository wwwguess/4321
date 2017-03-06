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
        set_name(YEL"����"NOR, ({"long wu", "longwu", "long" }));
	set("title", HIW"����ͷ"NOR);
	set("long", @LONG
�����ھֵ�����ͷ���壬�������̫�������Ѿ��������ˡ���˵���������׼ҵ�����
�ĸ��֡�
LONG
	);

	set("gender", "����");
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
		"����" : (: ask_for_hubiao :),
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
		return notify_fail("��ĵľ���̫�ͣ������ڼ����ھ֡�\n");
	else {
	if ( me->query("mark/�ھ�") )
		return notify_fail("���Ѿ������ˡ�\n");
/*
	if( !arg || arg !="�ھ�") return 0;*/
	me->set("mark/�ھ�", 1);
	command("say �ҾͰ������°ɡ�\n");
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
        
	return command("say С�ֵ��Ѿ���������Ҫ���Լ���ʦ��ѧ�ˣ��Ǻ�."); 
	
	if (query("count") < 1)
		return command("hehe");
	
	add("count", -1);    
	
	me->improve_skill("blade", 50);
	write("���������ͷ��̸������Ļ����������˽�����\n");
	return 1;
}

string ask_for_hubiao()
{
	object me;
	me = this_player();
	
	if( me->query("mark/�ھ�") )
	{
		if( me->query("mark/����") )
        		return RED"�㻹û�а����͵�����ô������?\n"NOR;        
       		if(query("count") < 1)
                	return "��Ǹ���������ˣ���ε����Ѿ����˻����ˣ����´ΰɡ�\n";

                add("count", -1);

                me->set_temp("pending/hubiao", 1);
                        return "���뻤�ڣ����Ǻ��£���·��Σ�գ����Ը��(want)��\n";
        }  else {
                return "��û�м��������ھ֣����ܻ��ڡ�\n";
        }
}

int do_want()
{
	object me;
	me=this_player();

	if( !me->query_temp("pending/hubiao") ) 
		return notify_fail("��Ҫ��ʲô��\n");
 	me->set("mark/����");
	command("say ��Ҫ���ڣ����Ǻ��£�����(follow)�����Ҵ���ȥ�Ҹ�����ͷҪ����\n");
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
        {command("say ����Ҫɱ�ң��㻹��������æ��!\n");
        call_out("step",1);
        return;
        }
        if (random(step_phase[j]["radom"])==1)             	
          {command("say ��ѽ������ɱ�֡�\n");
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
	 command("say ��������������ţ��������ý���ͷ����˵�������ˡ�\n");
	 this_player()->set("mark/����", 1);
	 this_object()->move("/d/suzhou/hfang");
         	 return;
         }
	call_out("step", 1);
}


	

