// sample master.c code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({"liang zhanglao", "liang", "zhanglao"}));
	set("title", "ؤ��Ŵ�����");
        set("title",MAG "ؤ��" NOR + YEL "�Ŵ�" NOR+ MAG "����" NOR);
        set("nickname", GRN "��������" NOR);
	set("gender", "����");
	set("age", 55);
	set("long", 
		"��������ؤ�������ã��书��ߵĳ��ϣ��������������Ѿá�\n"
		"ؤ���书������ǿ������������һ�����٣������������ϡ�\n");

	set("attitude", "peaceful");
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("kee", 2000);
	set("max_kee", 2000);
	set("gin", 400);
	set("max_gin", 400);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 120);
	
	set("combat_exp", 1200000);
	
	set_skill("force", 120); 
	set_skill("huntian-qigong", 125); 
        set_skill("strike", 125);
	set_skill("xianglong-zhang", 120); 
	set_skill("dodge", 123); 
	set_skill("xiaoyaoyou", 120); 
	set_skill("parry", 120); 
	set_skill("staff", 110); 
	set_skill("dagou-bang", 120); 
	set_skill("begging", 110); 
	set_skill("checking", 120);
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("staff", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("strike", "xianglong-zhang");
	
	create_family("ؤ��", 18, "�Ŵ�����");
	setup();
}

void init()
{
        object ob;
	mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) 
	{
		myfam = (mapping)ob->query("family");
		if (!myfam || myfam["family_name"] != "ؤ��")
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	message_vision("\n�����Ͽ���$N�����������һ�����㲻��ؤ����ӣ����ҹ���ȥ��\n\n", ob);
	call_out("kicking", 0, ob);	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	ob->move("/d/gaibang/inhole");
	message("vision","ֻ����ƹ����һ����" + ob->query("name") +
		"��С������˳�����\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="ؤ��")
        {
		command("say ����ؤ����Ҫһ��һ������"+ RANK_D->query_respect(ob)+ "��Ҫ��һ����������");
                return;
        }
        if (ob->query("dai")<8)
        {
               	command("say " + RANK_D->query_respect(ob) + "�Ĵ������������ܰ��ұ���");
                return;
        }
        if (ob->query("dai")== 8 )
        {
        	if ((int)ob->query("str") < 25) {
                	command("say ����ؤ�������һ���Ը���Ϊ����" +
                	RANK_D->query_respect(ob) + "����̫�����ƺ�����ѧؤ��Ĺ���");
                	return;
	        }

        	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
	        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
                command("recruit " + ob->query("id"));
                this_player()->set("title",MAG "ؤ��" NOR + YEL +"�˴�" NOR + MAG "����" NOR);
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α�������С�л��أ�");
        return;
}
