inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("���ӽ�", ({ "yu shangshu","yu" }));
        set("title","��������");
        set("gender", "����");
        set("age", 54);
        set("long",
                "���ǵ��������ߵĺ��ˣ��빬�еĹ�ϵҲ�����磬�����ƹ���\n"
		"�����Ȩ���������������λ�ã������ǽ�����Ϊ���������Ե\n"
		"�ʣ�����ս���պգ����н���ĵ�λ��\n"
		);
      create_family("��ͥ", 6, "��Ա");


        set("attitude", "peaceful");

        set("str", 27);
        set("int", 25);

        set("force", 1400);
        set("max_force", 800);
        set("force_factor", 10);
        set("max_gin", 200);
        set("eff_gin", 200);
        set("gin", 200);
        set("max_sen", 200);
        set("eff_sen", 200);
        set("sen", 200);

        set("combat_exp", 400000);
        set_skill("binfa",150);
         set_skill("yongren",150);
        set_skill("blade", 70);
        set_skill("shortsong-blade", 105);
        set_skill("force", 80);
        set_skill("fonxanforce", 80);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set_skill("fall-steps", 60);

        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("force", "fonxanforce");
        map_skill("dodge", "fall-steps");

        setup();

        carry_object(__DIR__"obj/blade")->wield();
}
void attempt_apprentice(object ob)
 {          
	command("smile");
	command("say �ܺ�,��ͥ��������֮������" + RANK_D->query_respect(ob) + 
        "���Ŭ�������ձض��гɡ�\n");
	command("recruit " + ob->query("id") );}
 
void recruit_apprentice(object ob)
         {
        	if( ::recruit_apprentice(ob) )
        	ob->set("class", "officer");
              ob->set("title","��ͥ���ߴ���Ա");
        }
