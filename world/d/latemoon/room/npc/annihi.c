inherit NPC;
 
void create()
{
         set_name("���ݶ�", ({ "annihier"  }) );
        set("gender", "Ů��" );
         set("age",37);
        set("long", @TEXT
TEXT
);
        set("attitude", "peaceful");
       set("class", "dancer");
       set("combat_exp", 5000000);
       set("score", 7000);
        set_skill("unarmed",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
	set_skill("parry", 100);
        set_skill("pyrobat-steps", 100);
        set_skill("snowshade-force", 100);
        set_skill("snowshade-sword", 100);
        set_skill("sword", 100);
        map_skill("sword","snowshade-sword");
	map_skill("parry","snowshade-sword");
        map_skill("force","snowshade-force");
         map_skill("dodge","pyrobat-steps");
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 10);
        create_family("�������", 1, "����");

        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/redbelt")->wear();
        carry_object("/d/latemoon/obj/sword")->wield();
}

void attempt_apprentice(object ob)
{
     command("say ��ʦ! ���ҵ����Ҷ�����!��ȥ�ҡ���Ƽ�����ˣ������ղ�����? ");
     return 0;
}
