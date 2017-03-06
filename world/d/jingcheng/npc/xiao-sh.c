// Created by ysgl
// Data: 1997.10.17
// The latest changed by ysgl in 1997.10.30
               
#include <ansi.h> 
inherit NPC;                               
mapping *step_phase;
mapping *read_table(string file);
int ask_biao(object me);
int j;

void create()
{
	set_name("����", ({ "xiao sheng", "xiao" ,"sheng" }));
	set("title",GRN"��Զ�ھ�����ͷ"NOR);
	set("nickname", GRN"����"NOR+HIY"һ��"NOR);
	set("long",
	"��������Զ�ھ����ڵĵ��ң������������������ո�ǿ������Ϊ�˺�ˬ����һ����\n"
	"����ĺ��ӡ��Դ�����ͷ�˳�����֮������Զ�ھִ��СС�����������һ�ִ���\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "heroism");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 35);   
	set("can_biao", 3);
	set("combat_exp", 60000+random(15000));
	set_skill("dodge", 100);
	set_skill("unarmed", 80);
	set_skill("sword", 120);
	set_skill("force",120);
	set_temp("apply/defense", 40);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"���������ĳ�����һ�ۣ��ع�ͷȥ���Ŷ��ٵ��������䡣\n",	
        }) );             
	set("inquiry", ([
		"Ѻ��" : "�������������ھִ���������ҵ���������ϣ������������֣����ڱ���������һ����Ҫ�ߣ���־�߿�\n"
		"�������Ѻ�ڣ�����ź񣡡�\n",
		"����"   : (: ask_biao :),
	]));
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/gangjian")->wield();
}
void init()
{
	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting() 
	&& !(this_object()->query_temp("is_biao")) )
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	object obj;
	command("hi "+me->query("id"));
}                       
int ask_biao(object me)
{          
	object ob = this_object();
	object player=this_player();

	if( ob->query("can_biao") <= 0 || ob->query_temp("is_biao") ) {
		message_vision("$NЦ�������������Ѿ�����Ѻ���ˣ�"+RANK_D->query_close(player)+
		"���ǵ���һ�˰ɡ���\n", ob);
		return 1;                 
	} else {
		message_vision("$NЦ������ "+RANK_D->query_respect(player)+"���Ե�Ƭ�̣��ڳ����Ͼͺá���"
		"\n", ob);
		this_object()->add("can_biao", -1);
		remove_call_out("anounce");
		call_out("anounce", 5,player);
		return 1;
	}
}
void anounce(object player)
{
	command("chat ����ά���������ά�����������");
	this_object()->set("chat_chance", 0);
	this_object()->set_temp("is_biao", 1);
	j = 0;
	step_phase = read_table(__DIR__"luxian");
	remove_call_out("ya_biao");
	call_out("ya_biao", 5,player);
}                              
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for( i = 0 ; i < sizeof(line) ; i++ ) {
		if( line[i] == "" || line[i][0] ==	'#' ) continue;
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
		if( line[i] == "" || line[i][0] == '#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]]);
		fn = (++fn) % sizeof(field);        
		if( !fn ) ++rn;
	}
	return data;
}
void ya_biao(object player)
{        
	object obj, place;     
	int i,jj;             

	if( this_object()->is_fighting() && this_object()->query_temp("is_biao") ) {
		if( random(10) > 6 )
			command("say ��Զ�ھ֡���������ά���������");
		call_out("ya_biao", 1,player);
		return;
        }
        if( random(step_phase[j]["random"]) > 5 ) { 
		tell_object(player,RED"ͻȻ�䣬������ð��һ�������������������ų��ڳ�����������\n"NOR);
		command("say ��ǿ�������С�Ļ��ڣ�");
		jj=2+random(4);
		for( i = 0 ; i < jj ; i ++ ){
		   	obj = new(__DIR__"xiaoer");
		   	obj->move( step_phase[j]["place"] );
	   		obj->kill_ob(this_object());
			this_object()->kill_ob(obj);
			obj->kill_ob(player);
			player->kill_ob(obj);
	           	
		}
		call_out("ya_biao", 5,player);
		return;
	}                
	place = load_object( step_phase[j]["place"] );           
	message_vision("$N�����ڳ����ꤡ������߹�"+place->query("short")+"������ǰ����\n", this_object());
	command(step_phase[j]["command"]);
        j++;               
        if( j == sizeof(step_phase)) {
		player->set_temp("done_biao", 1);
		command("pat "+player->query("id"));
		command("say �����ģ������ڵñ�ƽ��Ѻ�������Ƕ����"+RANK_D->query_respect(player)
		+"�Ĵ�ݰ���\n");
		command("say ���Ǹ���ĳ��");
		obj = new("/npc/money/gold");
		obj->set_amount( 50+random(50) );
		obj->move(player);
		message_vision("�������Ľ���$NһЩ�ƽ�\n", player);
		this_object()->delete_temp("is_biao");
	 	return;
	}
	call_out("ya_biao", 1,player);
	return;
}
