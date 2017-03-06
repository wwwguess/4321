// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

int ask_ren(object me);            
int ask_pipa(object me);

void create()
{
	set_name("�����", ({ "liu yuer" , "liu" , "yuer" }));
	set("title","���ĸ�Ů");
	set("long",
	"һ���¿������ĸ�Ů���������磬ֻ�п�����Ϊ����\n");
	set("gender", "Ů��");
	set("age", 24);
	set("attitude", "peaceful");  
	set("per", 35);
	set("combat_exp", 1000);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"��������˵��������õ��ң���ʼ��������������\n",	
		"�����������ͷ�ϵķ�˿��ǳǳ��һЦ��\n",
		"���������¥�µĽŲ�����һ˫�����ڴ����۾�����¥�ݿڣ�������ҡ��ҡͷ��\n",
		"�������������ǰ��СǮ���͵͵�̾��һ������\n",
        }) );
	set("inquiry",([
		"����"  : (: ask_pipa :),
		"����"  : (: ask_ren :),
	]));
		
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/pipa");
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
	object ob = this_object();
	message_vision("$NЦ�Ŷ�$n˵����λ"+RANK_D->query_respect(me)+
	"����������ū��Ϊ"+RANK_D->query_respect(me)+"������һ����\n", ob, me);
}

int ask_pipa(object me)
{
	object ob = this_object();
        
	message_vision("$N�����ı��Ż�������ã�Ψ�ֱ����˸������Ƶġ�\n", ob);
	message_vision("$N����$n���ֵ�˵���������������ҵ�����Ҳ�����\n", ob, this_player());
	                
         this_player()->set_temp("done",1);
         return 1;
}                                     

int ask_ren(object me)
{
	object ob = this_object(); 

	message_vision("$N����Ŀ���$n˵������λ"+RANK_D->query_respect(this_player())+
	"��ô֪�����ڵ��ˣ�\n", ob, this_player());
	command("sigh");
	tell_object(this_player(),"����������ɫ��˵����ֻ����Ȼ��ÿ�����˵�����������Ǯ���࣬����\n"
	"���ܳ�����ʮ���ƽ𰡡��µ����ֻ��ϣ����������ܴ󷢴ȱ��ˣ�������һ����·�ˡ�\n");
	return 1;
}

int accept_object(object who, object what)                  
{                  
	object ob, obj;
	ob = this_object();
	
	if( what->query("money_id") ){
		tell_object(who,"����������ҡҡͷ˵����л"+RANK_D->query_respect(who)
		+"���⣬\nСŮ�������ˣ���������»��������Լ��跨����ɡ�\n");
		return 1;
	}
	if( !(obj=present("baiyu pipa", ob)) ){
		tell_object(who,"���������һ��������ѽ���ҵ���������ȥ�ˡ�\n");
		return 1;
	}
	if( what->query("id") == "letter" && who->query_temp("done") ){
		tell_object(who,GRN"������ӹ��ţ��ҴҵĿ���һ��󣬸м��Ķ���˵��"
		+RANK_D->query_respect(who)+"��ȫ��\nСŮ�Ӳ�ʤ�м������Իر����ͽ���"
		"���������͸�"+RANK_D->query_respect(who)+"��������ɡ�\n");
		obj->move(who);
		message_vision("$N��$n���˸��򸣣������������ͣ�СŮ����͸���ˡ�\n", ob, who);
                this_player()->set_temp("done",0);
        	remove_call_out("dest");
		call_out("dest", 1, ob);
		return 1;
	}
	return 0;
}		
		 
void dest(object ob)
{
	destruct(ob);
}
