inherit NPC;
 
void create()
{
        set_name("���", ({ "Jane","jane" }) );
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
        set("force", 7000);
        set("max_force", 7000);
        set("force_factor", 30);
        create_family("����ׯ", 1, "ǰ��");

        setup();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/redbelt")->wear();
}

void attempt_apprentice(object ob)
{
     command("say ��ʦ! ���ҵ����Ҷ�����!��ȥ�ҡ���Ƽ�����ˣ������ղ�����? ");
     return 0;
}
