// zhang.c ������
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
void heal();
void create()
{
        set_name("������", ({ "zhang sanfeng", "zhang" }));
        set("nickname", HIR "��������" NOR);
        set("long",
                "�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ�\n"
                "��һ���ۻ�Ļ�ɫ���ۣ����ޱ߷���\n"
                "��ĸߴ��������꣬������⣬��ü�԰ס�\n");
	set("title",RED "�䵱��" NOR + GRN "��ɽ" NOR+ RED "��ʦ" NOR);
        set("gender", "����");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("kar", 30);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set("max_kee", 5000);
        set("max_gin", 3000);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 100);
          set("combat_exp", 5000000);
        set("score", 500000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
	set_skill("move", 200);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 180);
	set_skill("cuff", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 1, "��ɽ��ʦ");
        set("class", "taoist");

        setup();
        carry_object("/d/wudang/obj/zhenwu")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}


void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "�䵱��")
	{
		command("say ��ֻ�ձ��ŵ��ӣ�"+ RANK_D->query_respect(ob) + "���Ȱݹ��顣");
		return;
	}
        if ((int)ob->query_skill("taiji-shengong", 1) < 50) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }
/*
        if ((int)ob->query("shen") <50000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬��ѧ����");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
*/
        if (ob->query_int() < 30) {
                command("say ���䵱���书ȫ�ӵ��������");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ�������ǰ��Ҳ������");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ����
�ڣ�������ذɡ�");
                return;
        }
        command("chat ����������������");
        command("chat �벻���ϵ��ڴ���֮�꣬���ٵ�һ������֮�ţ����ǿ�ϲ�ɺء�")
;
        command("recruit " + ob->query("id"));
        this_player()->set("class", "taoist");
        if((string)this_player()->query("gender")!="Ů��")
                this_player()->set("title",RED "�䵱��" NOR + GRN +"����" NOR);
        else
	        this_player()->set("title",RED "�䵱��" NOR + GRN +"Ů����" NOR);
}

void init()
{

        object ob;
        mapping fam;

        ::init();
        add_action("give_quest","quest");
        ob = this_player();
/*
        if ( (int)ob->query("shen") <=2000 && ((fam = ob->query("family")) && fam["master_id"] == "zhang sanfeng"))
	{
		command("say ����ɱ��Խ����������Ϊ���������������ʦ����\n");
		command("expell "+ ob->query("id"));
	}
*/
}		

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 100");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}

int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� ʲô�������¸���𣿣�\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� ��ú�ѧѧ������Ҫ����ɣ�\n" ,who);
    who->set("quest",0);
    return(0);
}

