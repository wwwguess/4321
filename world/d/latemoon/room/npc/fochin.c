inherit NPC;
 
void create()
{
        set_name("�����", ({ "fochin","chin" }) );
        set("gender", "Ů��" );
        set("age", 27);
        set("long", @TEXT
����ɫ���㣬�������ף�����浾��������御�
�����ݾ��������������������������ŵ�һ����
���㡣
TEXT
);
       set("class", "dancer");
       set("combat_exp", 99000);
        set_skill("unarmed", 50);
        set_skill("dodge", 70);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 70);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 1000);
        set("max_force", 500);
       set_temp("apply/armor", 70);

        create_family("����ׯ",2,"����");
        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/belt")->wear();
        carry_object("/d/latemoon/obj/clasp")->wear();
        carry_object(__DIR__"obj/fire");
}

