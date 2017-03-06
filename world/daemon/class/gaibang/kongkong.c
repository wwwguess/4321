// kongkong.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void consider();
void heal();

void create()
{
	seteuid(getuid());
	set_name("�տն�", ({ "kong kong","beggar","kee gai","kong" }) );
        set("title", MAG "������ؤ" NOR);
	set("gender", "����" );
	set("age", 53);
	set("long", "һ��������˪֮ɫ������ؤ��\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_kee", 1500);
	set("max_gin", 800);
	set("force", 1200);
	set("max_force", 1200);
	set("force_factor", 110);
	set("shen_type", 0);

        set("startroom","/d/city/lichunyuan");

	set("thief", 0);
	set("combat_exp", 50000);

	set_skill("force", 100); 
        set_skill("strike", 100);
	set_skill("sword", 110);
	set_skill("dodge", 110);
	set_skill("parry", 110);
	set_skill("stealing", 130);
	set_skill("begging", 130);
	set_skill("checking", 110); 
	set_skill("huntian-qigong", 70); 
	set_skill("xianglong-zhang", 70);
	set_skill("xiaoyaoyou", 80); 

	map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");

        prepare_skill("strike", "xianglong-zhang");

	create_family("ؤ��", 19, "�˴�����");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
		(: exert_function, "recover" :)
        }) );

	set("chat_chance", 80);
	set("chat_msg", ({
		"�տն�˵��: ���ĵĴ�ү�ġ� ����Ҫ���ļ���ͭ��ɡ�\n",
		"�տն�������ش��˸���Ƿ��\n",
		"�տն�����׽ס�����ϵ�ʭ�ӣ����: ��������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
		(: heal :),
		(: random_move :)
	}) );

	setup();

        carry_object("/clone/food/jitui");
        carry_object("/clone/food/jiudai");
	add_money("silver", 10);
        
}

void attempt_apprentice(object ob)
{
        mapping fam;
	object obj;
	string title1;

	if( ob->query("combat_exp") >= 20000 && ob->query("family/family_name")!="ؤ��")
        {
        	command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α��������Ͻл��أ�");
		return ;
	}
        if ((string)ob->query("family/family_name")!="ؤ��")
	{
	    if(!ob->query("is_beggar"))
	    {
	        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        	"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        	command("recruit " + ob->query("id"));
		ob->set("dai", 1);
		if(ob->query("class")!="bonze")
		ob->set("class", "beggar");
        	if(!present("budai", this_player()))
		{
                obj=new("/d/gaibang/obj/gaibang-bag");
                obj->move(ob);
		}
	        this_player()->set("title",MAG "ؤ��" NOR + YEL +"һ��" NOR + MAG "����" NOR);
		this_player()->set("is_beggar", 1);
	    }
	    else
	    {
		command("say "+ RANK_D->query_respect(ob) + "��ǰ����ؤ����ӣ���Ȼ�г�����α��ֻ����أ�");
		return;
	    }
	}
	else
	{
		title1=this_player()->query("title");
	        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        	"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        	command("recruit " + ob->query("id"));
		this_player()->set("title", title1);
	}
}

		

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	mapping fam; 
 
	if( !ob || environment(ob) != environment() 
                || ((fam = ob->query("family")) && fam["family_name"] == "ؤ��")
                || (int)ob->query_skill("taoism", 1) > 30
                || ob->query_int() > 30
          ) return;

	switch( random(5) ) {
		case 0:
                       command("hehe " + ob->query("id"));
                       command("beg coin from " + ob->query("id"));
                       command("buy jitui");
		       break;
		case 1:
                       command("grin " + ob->query("id"));
                       command("steal silver from " + ob->query("id"));			
                       command("eat jitui");
		       break;
		case 2:
                       command("hi " + ob->query("id"));
                       command("steal gold from " + ob->query("id"));			
                       command("drink jiudai");
		       break;
		case 3:
                       command("pat " + ob->query("id"));
                       command("beg jiudai from " + ob->query("id"));	
                       command("eat jitui");
		       break;
		case 4:
                       command("walkby " + ob->query("id"));
                       command("beg jitui from " + ob->query("id"));	
                       command("drink jiudai");
		       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1) {
        	 command("smile");
	         command("say ��л�� ! ��ʵ�һ����е�Ǯ�ģ����ֻ������������� !");
        	 command("give 10 silver to " + me->query("id"));
	}
        else {
        	 command("shake");
	         command("say ���ֶ������Ҫ ! ��һ��ȥ !");
	         command("give " + obj->query("id") + " to " + me->query("id"));
//               obj->move(this_player());
        }

	return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
	return 0;
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_qi") < ob->query("max_kee") && ob->query("eff_qi") > ob->query("max_kee") / 5 )
        {
                command("exert lifeheal");
                ob->set("force_factor", 110);
                return;
        }

        if (ob->query("kee") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_jing"))
                command("exert regenerate");

        return;
}
