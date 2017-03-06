// feng.c ������

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������",({"feng qingyang","feng"}));
        set("long",
                "��ɽǰ�����ˣ�\n"
                "��������ʮ���ꡣ\n");
        set("nickname", RED "��ħ" NOR);
        set("title",GRN "��ɽ��" NOR + YEL "����" NOR);
        set("gender", "����");
        set("age", 65);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);

        set("max_kee", 1800);
        set("max_gin", 800);
        set("force", 2000);
        set("max_force", 2000);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	set("sen", 500);
	set("max_sen", 400);
        set("force_factor", 50);
          set("combat_exp", 5000000);
        set("score", 100000);

        set_skill("force",100);
        set_skill("huashan-neigong", 100);
        set_skill("dodge", 180);
        set_skill("huashan-shenfa", 180);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("dugu-jiujian",200);
        set_skill("literate", 150);
        set_skill("cuff", 110);
	set_skill("poyu-quan", 110);
        set_skill("strike", 110);
        set_skill("hunyuan-zhang", 110);

	map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");

        prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");

        create_family("��ɽ��",17,"����");

        setup();

        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
}

void attempt_apprentice(object ob)
{

	string title1;

	if ((string)ob->query("family/family_name")!="��ɽ��") 
	{
		command("say ������ɵ��ӣ��Ҳ������㡣");
		return ;
	}

	if ((string)ob->query("gender")=="����")
	{
		command("say �Ҳ��������ˡ�");
		return ;
	}


        if((int)ob->query("betrayer"))
	{
		command("say "+RANK_D->query_respect(ob)+"������ʦ���������塣���������㡣\n");
		return;
	}

        if ((int)this_player()->query_int() < 30 )
        {
                command("say ѧϰ���½���ҪҪ�кõ����ԣ�"+RANK_D->query_respect(ob)+"���ʲ�����");
                return;
        }
	write(sprintf("shen %d\n",(int)ob->query("shen")));
	if((int)ob->query("shen") < 0) 
	{
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                            "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ�"+RANK_D->query_respect(ob)+"���Ҿ��������ˣ�\n");
        command("say �����Ҫ�Ͷ����ƣ��������壡������Ϊ������������Ϊʦ������Ź���ģ�\n");
	title1=ob->query("title");
        command("recruit "+ob->query("id"));
	ob->set("title", title1);
        
}

