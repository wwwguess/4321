//power.c
//write by dfbb@hero

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�ϰ�", ({ "lord","laoban" }) );
	set("gender", "����" );
	set("age", 42);
	set("long",
		"һ�������ܸɵ�������\n");
	set("combat_exp", 10000);
	set("attitude", "heroism");
	set("rank_info/respect", "���");
	create_family("�������", 16, "����");
	set("title","˳����ջ");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
	set_skill("mo-zhang-jue",60);
        map_skill("unarmed","mo-zhang-jue");
        set_skill("mo-shan-jue",60);
        map_skill("dodge","mo-shan-jue");
	setup();

}

void init()
{	
	add_action("do_join", "join");
	add_action("do_swear", "swear");
	::init();
}

int do_join(string arg)
{
 int i;	
 object ob,who,*inv;

 who=this_player();

  if(who->query("family/family_name")=="�������")
  {
    inv = all_inventory(who);
    for(i=0; i<sizeof(inv); i++)
     {   
        if(strsrch(inv[i]->query("name"),"����")==-1)continue;
                
        write("���Ѿ���������̵���.\n");
        return 1;
     }
    ob = new("/d/heimuya/obj/yaopai");
    ob->move(who);
    write("�´ο�Ҫ�úñ���!!!\n");   
    return 1;
 }

 if(!arg) return notify_fail("��Ҫ����\n");
if(arg=="�������"&&strsrch(who->query("title"),"��ͨ����")!=-1)
 {
     if( who->query_temp("pending/rysj_swear") ) {
                command("say ��˵���棬�����������ڽ���������˵һǧ��Ҳû�á�");
                return 1;
 } else {
                command("say ����������ж���Ѫ���ж���" + RANK_D->query_respect(who)
                        + "���������ļ��룬�ҷ�����(swear)����");
                who->set_temp("pending/rysj_swear", 1);
		return 1;
        }
  }
  else
   {	
  	write("����������еĹ���������ȥ!!!\n");
	who->move("/d/heimuya/yidao5");
	message("vision","ֻ����ƹ����һ����" +  who->query("name") +
                "���˴ӿ�ջ����˳��� \n", environment(who), who);

	return 1;
    }	
  write("��Ҫ��ʲô\n");
  return 1;		
}

int do_swear(string arg)
{
	object ob,who;
	who=this_player();
        if( !who->query_temp("pending/rysj_swear") )
                return 0;
        if( !arg ) return notify_fail("��Ҫ��ʲ���ģ�\n");
        this_player()->set_temp("pending/rysj_swear", 0);
        message_vision("$N���ĵ������򱾽�������ħ����" + arg + "\n�պ���Υ����,����ʬ���ʳ�������!!!\n",this_player());
        if( strsrch(arg, "���ڽ���") >=0 ) {
                command("smile");
	        ob = new("/d/heimuya/obj/yaopai");
                ob->move(who);
    		who->create_family("�������", 16, "����");
		who->set("title",HIR "��"+HIB"��"+HIY "���" NOR + "����");
    		write("�ϰ�˵: ��ϲ��!���������������������̵�һԱ��!!!\n");
   		return 1;

        } else {
                command("say ���Ȼû�г���,������ذ�!\n");
		who->move("/d/heimuya/yidao5");
        message("vision","ֻ����ƹ����һ����" +  who->query("name") +
                "���˴ӿ�ջ����˳��� \n", environment(who), who);
                
        return 1;
		
        }
        return 1;
}

