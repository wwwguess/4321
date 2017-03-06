
// master.c
inherit NPC;
inherit F_VENDOR;
inherit F_MASTER;
inherit F_QUEST;

void create()
 {
	set_name("��è", ({ "master sb", "sb", "master" }) );
	set("nickname", "��è");
	set("gender", "����" );
	set("age", 21);
	set("str", 1300);
	set("cor", 30);
	set("cps", 30);
	set("int", 30);
	set("per", 30);
	set("con", 30);
	set("kar", 30);
	set("max_force", 3000);
	set("force", 4000);
	set("force_factor", 200);
	set("rank_info/respect", "��è");
	set("long",
		"��è�Ǹ���ò�������������ε������ˣ�ֻ���������ô\n"
		"Ҳ�²������������������ˣ�ֻ�����������һϮ�������Ե���\n"
		"���ޱȣ�һ˫��Ц��Ц���۾���ͻȻ���㿴��һ�ۣ��㲻����\n"
		"��һ����\n");
	create_family("�Ӻ�����", 4, "������");
	set("combat_exp", 2000000);
	set("score", 300000);
	set("chat_chance", 5);
	set("chat_msg", ({
	//	(: exert_function, "recover" :),
		"��è˵��������һ�ѽ����н�Ц�Ӻ���\n",
		"��è˵����Ҫʲô������ɣ�\n",
		"��è˵�����������������ˣ�\n",	}) );
     	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword", 110);
	set_skill("force", 100);
    //   set_skill("mysterrer",120);
       set_skill("hhu-sword", 110);
	set_skill("literate", 110);
	set_skill("wu-shun", 60);
	set_skill("linbo-steps", 110);
	map_skill("sword", "hhu-sword");
	map_skill("force", "wu-shun");
       map_skill("dodge", "linbo-steps");
       map_skill("parry","hhu-sword");
	set("inquiry", ([
		"�Ӻ�" : "�Ӻ��������ִ�ƣ����к�ָ�̣�",
		"��ʦ"   : "�������ߣ�����Ʒ�Ĳɣ���һ��������֮ѡ��",
         	"name": "�ұ�����è��������ң���������Ρ�",
		"here": "������ǺӺ���ѧ��",	]) );
              set("vendor_goods", ([
                "�����": "/u/sbaa/mianju",
                "��Ѫ��": "/u/sbaa/sbsword",
               "������":"/u/sbaa/buqidan",
                "������":"/u/sbaa/bujindan",
                "����":"/u/sbaa/busendan",
                "�󻹵�":"/u/sbaa/dahuan",
                "������":"/u/sbaa/sbcloth",   
                 "��ħ��":"/u/sbaa/tiandan", 
                "С¥һҹ������":"/u/sbaa/sbblade",   
                "��������¶":"/u/sbaa/txiang", ]) );

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 80);  
 
	        setup();
              carry_object(__DIR__"sbsword")->wield();
          	carry_object(__DIR__"sbcloth")->wear();

        
      }
 void init ()
{
	::init();
        add_action("give_quest","quest"); 
	add_action("do_vendor_list", "list");
}

   
void attempt_apprentice(object ob)
 {          
	command("smile");
	command("say �ܺê�" + RANK_D->query_respect(ob) + 
        "���Ŭ�������ձض��гɡ�\n");
	command("recruit " + ob->query("id") );}
 
void recruit_apprentice(object ob)
         {
        	if( ::recruit_apprentice(ob) )
        	ob->set("class", "fighter");
        }


