// fu_jiang 
// Made by ysg (1997.10.22)

#include <ansi.h>
inherit NPC;

#include "namedata.h"

void create()
{
        string name,nick;

	name = comm_man_name();
	nick = comm_man_nick();
	
        set_name(name, ({ "fu jiang" , "fu" , "jiang" }) );
	set("gender", "����");
        set("title",RED"������"NOR+BLU"����"NOR);
        set("nickname", nick);
	set("age", 35+random(20));
	set("long",
	"�����ŵ�����ϳ�������������ս��һ���������˽������λ�ã��������̫ƽ��Ҳûʲôʾ��\n"
	"���ˣ������������Է��߽��б䣬���������ͣ������û���¡�\n");
	set("combat_exp", 65000+random(65000));
        set("shen_type", 1);
	set("attitude", "heroism");
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		(HIY "���������ȵ����ð��������췴����\n" NOR),
		(HIG "�������͡���һ����Ц�����ߣ�������˰ɣ�\n" NOR),
        }) );

	set_skill("unarmed", 90);
	set_skill("parry", 90);
	set_skill("dodge", 90);
	
	create_family("������", 3, "����");

	setup();
        
	if(strsrch(nick,"��")!=-1)
	 {
          carry_object(__DIR__"obj/gangjian")->wield();
	  set_skill("sword",90);
	 }	
        else if(strsrch(nick,"��")!=-1)
	 {
          carry_object(__DIR__"obj/blade")->wield();
	  set_skill("blade",90);
	 }
        else if(strsrch(nick,"�")!=-1)
	 {
	  carry_object(__DIR__"obj/ji")->wield();
          set_skill("halberd",90);
         }
        else if(strsrch(nick,"��")!=-1)
	 {
	 carry_object(__DIR__"obj/hammer")->wield();
	 set_skill("hammer",90);
         }
        else if(strsrch(nick,"��")!=-1)
	 {
	  carry_object(__DIR__"obj/axe")->wield();
          set_skill("axe",90);
         }
        else if(strsrch(nick,"ǹ")!=-1)
	 {
          carry_object(__DIR__"obj/qiang")->wield();
          set_skill("qian",90);
         }
        else if(strsrch(nick,"��")!=-1)
	 {
          carry_object(__DIR__"obj/whip")->wield();
	  set_skill("whip",90);
         }
        carry_object(__DIR__"obj/cloth")->wear();
	add_money("silver", 20);
}

int accept_fight(object me)
{
        command("say "+RANK_D->query_rude(me)+"��Ȼ��ͬ�ٱ�����, ����!");
        command("grin");
        kill_ob(me);
        return 1;
}

int accept_kill(object killer)
{
 	int i;
	object *ob,me;
	me=this_object();
	ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( ob[i]->query("family/family_name")!="������") continue;
		if( ob[i]->query("id")==killer->query("id")) continue;
                if( userp(ob[i]) ) ob[i]->kill_ob(killer);
                else if( !ob[i]->is_killing(killer) ) ob[i]->kill_ob(killer);
		write(ob[i]->query("name")+ "���:"+RANK_D->query_rude(killer)+"��ȥ���ɣ� \n" );
        }
        return 1;
}



