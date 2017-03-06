// master.c

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("������",({"master outer","master","outer"}) );
	set("gender","����");
	set("age",48);
	set("str",21);
	set("cor",24);
	set("cps",27);
	set("int",30);
	set("per",28);
	set("con",30);
	set("kar",30);
	set("spi",30);

	set("max_force",2000);
	set("force",3000);
	set("force_factor",3);
	set("max_atman",1500);
	set("atman",2000);
	set("max_mana",2000);
	set("mana",4000);
	set("long",
	"�����ӱ�Ϊ�ͼ��ˣ��������ָ�㣬����������У����˫�ޣ�\n"
	"���뻯������ñ���ɽ�󴨣��Ժž��������˾���һ�ɡ�\n" );
	
	create_family("������",1,"��ʦ");
	set("combat_exp",2000000);
	set("score",200000);
	set("chat_chance_combat",40);
	set("chat_msg_combat", ({
		(:cast_spell, "dun" :),
		(:cast_spell, "saveme" :),
		"�����ӵ�����Ϊ���޹����£��������ޣ�\n",
"�����ӵ���ƶ�����Զ���Ϊ�֣���ο������ƣ�\n",

	}) ) ;
	
	set_skill("force",120);
	set_skill("dodge",100);
	set_skill("parry",120);
	set_skill("unarmed",80);
	set_skill("sword",100);
	set_skill("staff",100);
	set_skill("literate",120);
	set_skill("tao-mystery",120);
	set_skill("perception",100);
	set_skill("magic",150);
	set_skill("spells",150);

	set_skill("juechen-force",120);
	set_skill("magic-array",120);
	set_skill("jingang-staff",100);
		
	map_skill("staff","jingang-staff");
	map_skill("spells","magic-array");
	map_skill("force","juechen-force");

        set("inquiry", ([
                "������" : "�������������������к�ָ�̣�",
                "��ʦ"   : "�������ߣ����л۸���",
                "name": "�ұ��Ǿ����ӡ�",
              ]) );
                setup();
                carry_object(__DIR__"jingang_staff")->wield();
                carry_object(__DIR__"hat")->wear();
      }

void attempt_apprentice(object ob)
 {

        if((string)ob->query("title")!="��ͨ����")
         {
            command("chat "+ob->query("title")+ob->query("nickname")+
            ob->query("name")+"Ҫ��ʦ������");
            command("grin");
            kill_ob(ob);
            return;
         }

        if( ((int)ob->query("spi") < 24))
          {     command("say �������ߣ����л۸���" +
              RANK_D->query_respect(ob) + "�����ʲ��ˣ�");
               return; }

	if ( ob->query("combat_exp") < 100000 ) {
		command("say "+RANK_D->query_respect(ob) + "�ƺ���ȱ��������������Ͷ��������¡�" );
		return ;
	} 

        command("smile");
        command("say �ܺê�" + RANK_D->query_respect(ob) +
        "���Ŭ�������ձض��гɡ�\n");
        command("recruit " + ob->query("id") );}

void recruit_apprentice(object ob)
         {
                if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
        }




