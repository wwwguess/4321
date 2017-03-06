// ning.c ������
#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void create()
{
        set_name("������",({"ning zhongze","ning"}));
        set("nickname", MAG "����Ů��" NOR);
        set("title",GRN "��ɽ��" NOR + YEL "��ʮ�˴�" NOR+ GRN "���ŷ���" NOR);
        set("long",
                "��ɽ����������Ⱥ�ķ��ˡ� \n"
               "�����꽫����ʮ, �˳�����Ů��.\n");
        set("gender", "Ů��");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 28);
        set("con", 26);
        set("dex", 30);
	set("per", 25);
        set("max_kee", 1000);
        set("max_gin", 800);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);
        set("combat_exp", 900000);
        set("score", 40000);
        set_skill("force", 140);
        set_skill("huashan-neigong", 140);
        set_skill("dodge", 120);
        set_skill("huashan-shenfa", 120);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("huashan-jianfa", 100);
        set_skill("purple", 80);
        set_skill("literate", 100);
        set_skill("strike", 60);
        set_skill("hunyuan-zhang", 60);
	set_skill("cuff", 80);
		set_skill("poyu-quan", 100);

        map_skill("strike", "hunyuan-zhang");
	map_skill("cuff", "poyu-quan");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");

        create_family("��ɽ��",18,"����");
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/zishan")->wear();
}

void attempt_apprentice(object ob)
{
        if((int)ob->query("betrayer")>=10)
        {
                command("say "+RANK_D->query_respect(ob)+"��α������壬���������㡣");
                return;
        }
        else if ((string)ob->query("gender")=="����" && ob->query_skill("pixie-jian")>=50)
        {
                command("say �ҿ����򶫳������ļ�ϸ��");
                return;
        }
        if((string)ob->query("gender")=="Ů��")
          {
               if ((int)ob->query("max_force") <200) {
                       command("say �һ�ɽ��ԭ�н��ڡ�����֮������������Ϊ�ס�");
                       command("say " + RANK_D->query_respect(ob) +"�Ƿ�Ӧ�ö�����������");
                       return;
               }
               if ((int)ob->query("shen") < 1000) {
                       command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                       command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +"�Ƿ����ò�����");
                       return;
               }
          command("say �ðɣ�" + RANK_D->query_respect(ob) +"���Ҿ��������ˣ�");
          command("recruit "+ob->query("id"));
        

           }
        else {
          command("say �Ҳ����е��ӣ�" + RANK_D->query_respect(ob) +"��ô�����ҿ���Ц�أ��㻹��ȥ����ʦ�ְɣ�\n");
            };
}

void init()
{

        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (((int)ob->query("shen")<500 || (int)ob->query("bad") >=3) && ((fam = ob->query("family")) && fam["master_id"] == "ning zhongze"))
        {
                command("say ����ɱ�����ˣ����Ž̲��ģ��������������ʦ����\n");
		ob->set("bad", 0);
                command("expell "+ ob->query("id"));
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                if (this_player()->query("shen")<10000)
                {
                        ob->set("title",GRN "��ɽ��" NOR + YEL +"Ů����" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "��ɽ��" NOR + YEL +"Ů����" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("shen")<10000)
                {
                        student->set("title",GRN "��ɽ��" NOR + YEL +"Ů����" NOR);
                        return;
                }
                else
                {
                        student->set("title",GRN "��ɽ��" NOR + YEL +"Ů����" NOR);
                        return;
                }
}
