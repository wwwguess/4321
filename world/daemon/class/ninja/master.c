
// master.c
inherit NPC;
inherit F_MASTER;
void create()
 {
	set_name("��ң��", ({ "master happyman", "happyman", "master" }) );
	set("nickname", "Ц�쳾");
	set("gender", "����" );
	set("age", 41);
	set("str", 27);
	set("cor", 30);
	set("cps", 20);
	set("int", 30);
	set("per", 30);
	set("con", 30);
	set("kar", 30);
	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 20);
	set("rank_info/respect", "������");
	set("long",
		"��ң���Ǹ���ò�������������ε������ˣ�ֻ���������ô\n"
		"Ҳ�²������У������ˣ�ֻ�����������һϮ�������Ե���\n"
		"���ޱȣ�һ˫��Ц��Ц���۾���ͻȻ���㿴��һ�ۣ��㲻����\n"
		"��һ����\n");
	create_family("��ң��", 4, "������");
	set("combat_exp", 2000000);
	set("score", 300000);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		"�쳾���Ц������������\n",
		"ƾ˭֪�������ܱ�������\n",
		"�ԾƵ��裬��������\n",	}) );
        set_skill("unarmed", 150);
     	set_skill("parry", 120);
	set_skill("dodge", 150);
	set_skill("sword", 100);
	set_skill("force", 150);
	set_skill("literate", 150);
	set_skill("wu-shun", 120);
	set_skill("linbo-steps", 150);
	set_skill("ts-fist", 120);
	map_skill("unarmed", "ts-fist");
	map_skill("force", "wu-shun");
        map_skill("dodge", "linbo-steps");
	set("inquiry", ([
		"��ң��" : "��ң���Ż�����ִ�ƣ����к�ָ�̣�",
		"��ʦ"   : "�������ߣ�����Ʒ�Ĳɣ���һ��������֮ѡ��",
         	"name": "�ұ�����ң�ӣ�������ң���������Ρ�",
		"here": "��������ﻷ���ء�",	]) );
	        setup();
        	carry_object(__DIR__"seven_belt")->wear();
        	carry_object(__DIR__"green_dress")->wear();
      }
   
void attempt_apprentice(object ob)
 {
	if( ((int)ob->query("per") < 25)) 
          {     command("say �������ߣ�����Ʒ�Ĳɣ���һ��������֮ѡ��" +
              RANK_D->query_respect(ob) + "�����ʲ��ˣ�");
               return; }
                         
        if (  ((int)ob->query_skill("literate",1) < 50) ) 
	  {	command("say �������ߣ�����Ʒ�Ĳɣ���һ��������֮ѡ��" + 
              RANK_D->query_respect(ob) + "���Ĳɲ��ˣ�");
		return;	}

	if((string)ob->query("title")!="��ͨ����")
       	 {
	    command("chat "+ob->query("title")+ob->query("nickname")+
            ob->query("name")+"Ҫ��ʦ������");	 
            command("grin");
	    kill_ob(ob);
	    return;
	 }

	command("smile");
	command("say �ܺê�" + RANK_D->query_respect(ob) + 
        "���Ŭ�������ձض��гɡ�\n");
	command("recruit " + ob->query("id") );}
 
void recruit_apprentice(object ob)
         {
        	if( ::recruit_apprentice(ob) )
        	ob->set("class", "fighter");
        }
